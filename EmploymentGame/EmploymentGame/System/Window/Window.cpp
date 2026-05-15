#include "Window.h"


// メッセージ処理
// OSから送られてくるイベントを処理
LRESULT CALLBACK CWindow::WindowProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
	case WM_DESTROY:	// ウィンドウが閉じられたとき

		// アプリ終了メッセージを送信
		PostQuitMessage(0);
		return 0;
	}

	// 未処理メッセージはデフォルト処理へ
	return DefWindowProc(hWnd, msg, wp, lp);
}

// ゲームウィンドウ作成
bool CWindow::Create(HINSTANCE hInst, int width, int height, const wchar_t* title)
{
	// ウィンドウクラス情報の設定
	WNDCLASS wc = {};
	// メッセージ処理
	wc.lpfnWndProc = WindowProc;
	// クラス名
	wc.lpszClassName = L"DX11WindowClass";
	wc.hInstance = hInst;

	// ウィンドウクラス登録
	RegisterClass(&wc);

	// ウィンドウ作成
	m_hWnd = CreateWindow(
		wc.lpszClassName,		// クラス名
		title,	// タイトル
		WS_OVERLAPPEDWINDOW,	// 通常ウィンドウ
		CW_USEDEFAULT,					// X座標
		CW_USEDEFAULT,					// Y座標
		width,					// 横幅
		height,					// 高さ
		nullptr,
		nullptr,
		hInst,
		nullptr);

	// 作成失敗
	if (!m_hWnd) return false;

	// ウィンドウ表示
	ShowWindow(m_hWnd, SW_SHOW);

	return true;
}

LRESULT WindowProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	return LRESULT();
}
