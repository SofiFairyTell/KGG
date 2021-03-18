/*Curve formula
   p = R*sin(4/7 * t) where t e (0,14PI)
*/

#define PI 3.1415


#include <Windows.h>
#include <gdiplus.h>
#include <cmath>


using namespace Gdiplus;
#pragma comment(lib,"GdiPlus.lib")

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
void draw(HDC);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {

    const wchar_t windowName[] = L"Window Class";

    GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusTokens;
    GdiplusStartup(&gdiplusTokens, &gdiplusStartupInput, NULL);

    WNDCLASS wnd;
    wnd.cbClsExtra = 0;
    wnd.cbWndExtra = 0;
    wnd.hCursor = LoadCursor(0, IDC_ARROW);
    wnd.hIcon = LoadIcon(0, IDI_WINLOGO);
    wnd.lpszMenuName = 0;
    wnd.style = 0;
    wnd.hbrBackground = 0;
    wnd.lpfnWndProc = WndProc;
    wnd.hInstance = hInstance;
    wnd.lpszClassName = windowName;

    RegisterClass(&wnd);

    HWND hWnd = CreateWindowEx(
        0,
        windowName,
        L"Лабораторная работа №2 задание 2",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        NULL,
        NULL,
        hInstance,
        NULL
    );


    if (hWnd == NULL) {
        //Pause
        system("PAUSE");
        return -1;
    }

    ShowWindow(hWnd, nCmdShow);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    GdiplusShutdown(gdiplusTokens);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_QUIT:
        PostQuitMessage(0);
        return 0;
    case WM_PAINT:
    {
       PAINTSTRUCT ps;
       HDC hDc = BeginPaint(hWnd, &ps);
       FillRect(hDc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
       EndPaint(hWnd, &ps);
       return 0;
    }
    default:
        return DefWindowProc(hWnd,msg,wParam,lParam);
        break;
    }
}

void draw(HDC hdc)
{
    // Прорисовка кривой
}
