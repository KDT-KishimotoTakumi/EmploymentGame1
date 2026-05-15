#include <Windows.h>
#include "../System/Window/Window.h"
#include "../Graphics/Renderer/Renderer.h"

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int)
{
	// ウィンドウ生成
	CWindow window;
	if (!window.Create(hInst, 1280, 720, L"DX11 Game"))
		return -1;

	// DirectX初期化
	Renderer renderer;
	if (!renderer.Initialize(window.GetHWND(), 1280, 720))
		return -1;

	MSG msg = {};

	// メインループ
	// Windows メッセージ処理と描画を並行して行う
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			// 描画処理
			renderer.Render();
		}
	}

	// 終了処理
	renderer.Finalize();
	return 0;
}