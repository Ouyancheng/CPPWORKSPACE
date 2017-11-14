#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <string.h>
#include <wchar.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	//MessageBox(NULL, TEXT("The Window should be created! "), TEXT("Creating"), MB_OK | MB_ICONINFORMATION);
	static TCHAR szAppName[] = TEXT("HELLO WORLD!~ ");
	static TCHAR szTitle[] = TEXT("Hello Title!~ ");
	HWND hwnd;
	MSG msg;
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOWFRAME); //COLOR_WINDOW+1==COLOR_WINDOWFRAME
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szAppName;
	wcex.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	if (!RegisterClassEx(&wcex)) {
		MessageBox(NULL,
			TEXT("This Application must be run on Win32 platform! "),
			szAppName,
			MB_ICONERROR);
		return 1;
	}

	hwnd = CreateWindow(
		szAppName,
		//TEXT("My First Win32 Application"),
		szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		800, 600,
		NULL,
		NULL,
		hInstance,
		NULL);
	if (!hwnd) {
		MessageBox(NULL, TEXT("Call to CreateWindow failed! "), TEXT("My First Win32 Application"), MB_ICONERROR);
		return 1;
	}
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);

	}


	return (int)msg.wParam;
}

LRESULT WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;
	//TCHAR greeting[] = TEXT("Hello World! ");


	switch (message) {
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, TEXT("Hello!~ "), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		DrawText(hdc, TEXT("Hello!~ "), -1, &rect, DT_SINGLELINE | DT_LEFT | DT_VCENTER);
		DrawText(hdc, TEXT("Hello!~ "), -1, &rect, DT_SINGLELINE | DT_RIGHT | DT_VCENTER);
		DrawText(hdc, TEXT("Hello!~ "), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_TOP);
		DrawText(hdc, TEXT("Hello!~ "), -1, &rect, DT_SINGLELINE | DT_LEFT | DT_TOP);
		DrawText(hdc, TEXT("Hello!~ "), -1, &rect, DT_SINGLELINE | DT_RIGHT | DT_TOP);
		DrawText(hdc, TEXT("Hello!~ "), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_BOTTOM);
		DrawText(hdc, TEXT("Hello!~ "), -1, &rect, DT_SINGLELINE | DT_LEFT | DT_BOTTOM);
		DrawText(hdc, TEXT("Hello!~ "), -1, &rect, DT_SINGLELINE | DT_RIGHT | DT_BOTTOM);

		//EndPaint(hwnd, &ps);
		//break;
		//hdc = BeginPaint(hwnd, &ps);
		/*for (int i = 0; i < 100; i++) {
			TextOut(hdc,
				18 + i * 18, 18 + i * 18,
				greeting, _tcslen(greeting));
			TextOut(hdc,
				800 - (18 + i * 18), (18 + i * 18),
				greeting, _tcslen(greeting));
		}*/


		EndPaint(hwnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
		break;
	}
	return 0;
}
