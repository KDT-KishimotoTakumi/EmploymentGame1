#pragma once

#include <Windows.h>

class CWindow
{
public:
	/// <summary>
	/// ウィンドウの生成
	/// </summary>
	/// <param name="hInst">アプリケーションインスタンス</param>
	/// <param name="width">クライアント領域サイズ</param>
	/// <param name="height">クライアント領域サイズ</param>
	/// <param name="title">ウィンドウタイトル</param>
	/// <returns>作成したウィンドウハンドル</returns>
	bool Create(HINSTANCE hInst, int width, int height, const wchar_t* title);

	// 作成したウィンドウハンドルを外部に渡す
	HWND GetHWND() const { return m_hWnd; }

	// 作成したウィンドウハンドル
	static HWND m_hWnd;

private:
	// Windows メッセージ処理関数（性的関数である必要がある）
	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);


};