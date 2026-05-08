#include "Window.h"

HWND g_hWnd = nullptr;

LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
	case WM_DESTROY:	// ウィンドウが閉じられたとき

		// アプリ終了メッセージを送信
		PostQuitMessage(0);

		return 0;
	}

	// デフォルト処理
	return DefWindowProc(hWnd, msg, wp, lp);
}

// ゲームウィンドウ作成
bool CreateGameWindow(HINSTANCE hInst)
{
	// ウィンドウクラス情報
	WNDCLASS wc = {};

	// メッセージ処理
	wc.lpfnWndProc = WindowProc;

	// クラス名
	wc.lpszClassName = L"DX11WindowClass";

	// ウィンドウクラス登録
	RegisterClass(&wc);

	// ウィンドウ作成
	g_hWnd = CreateWindow(
		wc.lpszClassName,		// クラス名
		L"DirectX11 Window",	// タイトル
		WS_OVERLAPPEDWINDOW,	// 通常ウィンドウ
		100,					// X座標
		100,					// Y座標
		1280,					// 横幅
		720,					// 高さ
		nullptr,
		nullptr,
		hInst,
		nullptr);

	// 作成失敗
	if (!g_hWnd) return false;

	// ウィンドウ表示
	ShowWindow(g_hWnd, SW_SHOW);

	return true;
}