// Polyline.cpp : Defines the entry point for the application.
//

#include "pch.h"
#include "framework.h"
#include "Polyline.h"
#include "Point.h"
#include "Line.h"
#include "Bezier.h"
#define MAX_LOADSTRING 100

static Point l1[4] = { Point(50,100),Point(100,50),Point(200,50),Point(400,100) };
static Point l2[3] = { Point(500,100),Point(500,45),Point(100,600) };
static Point l3[5] = { Point(700,270),Point(800,50),Point(900,40),Point(700,600),Point(500,400)};
static Point b1[4] = { Point(400,100),Point(100,50),Point(200,400),Point(500,100)};
static Point b2[4] = { Point(100,600),Point(400,500),Point(600,900),Point(700,270) };
Operation* pO[] = {
    new Line(4,l1),
    new Bezier(b1),
    new Line(3,l2),
    new Bezier(b2),
    new Line(5,l3),
};
const int n = sizeof(pO) / sizeof(pO[0]);

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_POLYLINE, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_POLYLINE));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_POLYLINE));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_POLYLINE);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_UP:
            for (int i = 0; i < n; i++)
            {
                pO[i]->move(0, -10);
            }
            InvalidateRect(hWnd, NULL, true);
            break;
        case VK_DOWN:
            for (int i = 0; i < n; i++)
            {
                pO[i]->move(0, +10);
            }
            InvalidateRect(hWnd, NULL, true);
            break;
        case VK_LEFT:
            for (int i = 0; i < n; i++)
            {
                pO[i]->move(-10, 0);
            }
            InvalidateRect(hWnd, NULL, true);
            break;
        case VK_RIGHT:
            for (int i = 0; i < n; i++)
            {
                pO[i]->move(10, 0);
            }
            InvalidateRect(hWnd, NULL, true);
            break;
        }
    case WM_CHAR:
        switch (TCHAR(wParam))
        {
        case '+':
            for (int i = 0; i < n; i++)
            {
                pO[i]->zoom(1.2);
            }
            InvalidateRect(hWnd, NULL, true);
            break;
        case '-':
            for (int i = 0; i < n; i++)
            {
                pO[i]->zoom(1/1.2);
            }
            InvalidateRect(hWnd, NULL, true);
            break;
        }
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // TODO: Add any drawing code that uses hdc here...               

        // Ve hinh
        for (int i = 0; i < n; i++)
        {
            pO[i]->draw(hdc);
        }
        // Tinh length
        double length = 0;
        for (int i = 0; i < n; i++) {
            length += pO[i]->getLength();
        }
        char s[256] = { 0 };
        sprintf_s(s, "Length: %f\n", length);
        OutputDebugStringA((LPCSTR)s);
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
