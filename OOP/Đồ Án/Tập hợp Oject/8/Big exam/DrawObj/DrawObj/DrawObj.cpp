// DrawObj.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "DrawObj.h"
#include "ellipse.h"

#define MAX_LOADSTRING 100

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
    LoadStringW(hInstance, IDC_DRAWOBJ, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DRAWOBJ));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DRAWOBJ));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_DRAWOBJ);
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

enum { DRAW, MOVE };
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static const int MAX_ELLIPSE = 50;
	PAINTSTRUCT ps;
	HDC hdc;
	// TCHAR szHello[MAX_LOADSTRING];
	static int xc, yc, px, py;
	static CEllipse ae[MAX_ELLIPSE];
	static HBRUSH hbr;
	static HCURSOR hCursorMove, hCursorCross;
	static HPEN hPenDot;
	int dx, dy, i;
	static INT flag = DRAW, nEllipse, nCur = -1;
	RECT rt;
	static TCHAR szHelp[128] = L"Bam chuot va keo le de ve. Bam chuot ben trong 1 hinh và keo le de di chuyen";
	static TCHAR szBuf[128] = L"Hello world";

    switch (message)
    {
	case WM_CREATE:
		GetClientRect(hWnd, &rt);
		hbr = CreateHatchBrush(HS_DIAGCROSS, RGB(255, 0, 0));
		hCursorMove = LoadCursor(NULL, IDC_SIZEALL);
		hCursorCross = LoadCursor(NULL, IDC_CROSS);
		hPenDot = CreatePen(PS_DOT, 1, RGB(0, 0, 255));
		break;
	case WM_COMMAND:
        {
            int wmId = GET_X_LPARAM(wParam);
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

	case WM_LBUTTONDOWN:
		xc = GET_X_LPARAM(lParam); yc = GET_Y_LPARAM(lParam);
		if ((nCur = FindEllipse(ae, nEllipse, xc, yc)) >= 0)
		{
			flag = MOVE;
			hdc = GetDC(hWnd);
			SelectObject(hdc, hPenDot);
			SetROP2(hdc, R2_NOTXORPEN);
			ae[nCur].draw(hdc);
			SetCursor(hCursorMove);
			SetCapture(hWnd);
		}
		else if (nEllipse < MAX_ELLIPSE)// DRAW
		{
			flag = DRAW;
			ae[nEllipse].set(xc, yc, xc, yc);
			hdc = GetDC(hWnd);
			SetROP2(hdc, R2_NOTXORPEN);
			ae[nEllipse].draw(hdc);
			SetCursor(hCursorCross);
			SetCapture(hWnd);
			nEllipse++;
		}
		else
			flag = -1;
		break;

	case WM_MOUSEMOVE:
		if (GetCapture() == hWnd)
		{
			if (flag == MOVE)
			{
				hdc = GetDC(hWnd);
				SelectObject(hdc, hPenDot);
				SetROP2(hdc, R2_NOTXORPEN);
				ae[nCur].draw(hdc);
				px = xc; py = yc;
				xc = GET_X_LPARAM(lParam); yc = GET_Y_LPARAM(lParam);
				dx = xc - px, dy = yc - py;
				ae[nCur].move(dx, dy);
				ae[nCur].draw(hdc);
			}
			else if (flag == DRAW)
			{
				hdc = GetDC(hWnd);
				SetROP2(hdc, R2_NOTXORPEN);
				ae[nEllipse - 1].draw(hdc);
				ae[nEllipse - 1].set2(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
				ae[nEllipse - 1].draw(hdc);
			}
		}
		break;

	case WM_LBUTTONUP:
		if (GetCapture() == hWnd)
		{
			ReleaseCapture();
			InvalidateRect(hWnd, NULL, TRUE);
		}
		break;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		SelectObject(hdc, hbr);
		for (i = 0; i < nEllipse; i++)
			ae[i].draw(hdc);
		wsprintf(szBuf, L"Number of Ellipses: %d", nEllipse);
		GetClientRect(hWnd, &rt);
		DrawText(hdc, szBuf, lstrlen(szBuf), &rt, DT_CENTER);
		DrawText(hdc, szHelp, lstrlen(szHelp), &rt, DT_CENTER | DT_BOTTOM | DT_SINGLELINE);
		EndPaint(hWnd, &ps);
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
        if (GET_X_LPARAM(wParam) == IDOK || GET_X_LPARAM(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, GET_X_LPARAM(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
