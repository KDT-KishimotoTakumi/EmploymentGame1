#include "Renderer.h"

bool Renderer::Initialize(HWND hWnd, int width, int height)
{
	// スワップチェインの設定
	// バックバッファの枚数やフォーマット、出力先ウィンドウを定義
	DXGI_SWAP_CHAIN_DESC scd = {};
	scd.BufferCount = 1;
	scd.BufferDesc.Width = width;
	scd.BufferDesc.Height = height;
	scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	scd.OutputWindow = hWnd;
	scd.SampleDesc.Count = 1;
	scd.Windowed = TRUE;

	D3D_FEATURE_LEVEL fl;

	// デバイス・コンテキスト・スワップチェインを同時生成
	if (FAILED(D3D11CreateDeviceAndSwapChain(
		nullptr,
		D3D_DRIVER_TYPE_HARDWARE,
		nullptr,
		0,
		nullptr,
		0,
		D3D11_SDK_VERSION,
		&scd,
		&m_SwapChain,
		&m_Device,
		&fl,
		&m_Context)))
	{
		return false;
	}

	// バックバッファからレンダーターゲットビューを生成する
	Microsoft::WRL::ComPtr<ID3D11Texture2D> BackBuffer;
	m_SwapChain->GetBuffer(0, IID_PPV_ARGS(&BackBuffer));
	m_Device->CreateRenderTargetView(BackBuffer.Get(), nullptr, &m_RTV);
	return true;
}

void Renderer::Render()
{

	// 画面クリア色
	float clearColor[4] = { 0.1f, 0.2f, 0.4f, 1.0f };

	// 描画先
	m_Context->OMSetRenderTargets(1, m_RTV.GetAddressOf(), nullptr);

	// バックバッファ
	m_Context->ClearRenderTargetView(m_RTV.Get(), clearColor);

	// 画面に反映（垂直同期あり）
	m_SwapChain->Present(1, 0);
}

void Renderer::Finalize()
{
	// ComPtr により自動開放されるが明示的に Reset しておく
	m_RTV.Reset();
	m_SwapChain.Reset();
	m_Context.Reset();
	m_Device.Reset();
}
