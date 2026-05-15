#pragma once
#include <d3d11.h>
#include <wrl.h>

// DirectX描画クラス
// Win32 の詳細は知らず、HWND のみを受け取って初期化する
class Renderer
{
public:

	// DirectX 初期化
	bool Initialize(HWND hWnd, int width, int height);

	// 毎フレーム呼ばれる描画処理
	void Render();

	// 終了処理
	void Finalize();

private:

	// COMオブジェクトは ComPtr で自動開放管理
	Microsoft::WRL::ComPtr<ID3D11Device> m_Device;			// 描画に必要なオブジェクトを保持
	Microsoft::WRL::ComPtr<ID3D11DeviceContext> m_Context;
	Microsoft::WRL::ComPtr<IDXGISwapChain> m_SwapChain;
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> m_RTV;	// 描画先ビュー
};
