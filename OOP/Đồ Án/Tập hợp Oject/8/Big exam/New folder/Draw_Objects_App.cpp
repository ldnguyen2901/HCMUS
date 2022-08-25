// Draw_Objects_App.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Draw_Objects_App.h"
#include "Shape.h"
#include "Polygon.h"
#include "Quadrangle.h"
#include "Triangle.h"
#include "Ellipse.h"

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
    LoadStringW(hInstance, IDC_DRAWOBJECTSAPP, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DRAWOBJECTSAPP));

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

    return (int)msg.wParam;
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

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DRAWOBJECTSAPP));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_DRAWOBJECTSAPP);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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
    int wmId, wmEvent;
    PAINTSTRUCT ps;
    HDC hdc;
    //wchar
    static wchar_t szInfor[500] = L"Chuong trinh ve va thao tac hinh";
    static wchar_t szArea[500] = L"";
    //brush and pen
    static HBRUSH hbr;
    static HPEN hPenDot, penDot, penBorder;
    //cursor
    static HCURSOR hCursorMove, hCursorCross;
    //variable
    static const int MAX_SHAPE = 50;
    static int xc, yc, px, py;
    static INT nCur = -1;
    int dx, dy, i;
    RECT rt;
    //objects
    static Point T(200, 300);
    static _Ellipse A;
    static _Shape* aS[] = {
        new _Ellipse(400,250,200,100),
        new _Rectangle(200, 100, 300, 200),
        new _Circle(300, 300, 150),
        new _Triangle,
        new _Quadrangle,
        new _Trapezoid(100, 100, 50, 100, 250, 100),
        new _Parallelogram(100, 100, 200, 200, 100),
        new _Square(100, 100, 200)
    };
    static int h = 0;
    const int n = sizeof(aS) / sizeof(aS[0]);
    static _Shape* pS = aS[h];
    switch (message)
    {
    case WM_CREATE:
        GetClientRect(hWnd, &rt);
        penDot = CreatePen(PS_DOT, 1, RGB(0, 0, 255));
        hbr = CreateHatchBrush(HS_DIAGCROSS, RGB(255, 0, 0));
        hCursorMove = LoadCursor(NULL, IDC_SIZEALL);
        hCursorCross = LoadCursor(NULL, IDC_CROSS);
        penBorder = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
        break;
    case WM_LBUTTONDOWN:
        xc = GET_X_LPARAM(lParam); yc = GET_Y_LPARAM(lParam);
        if (aS[h]->isPointInside(Point(xc, yc)))
        {
            hdc = GetDC(hWnd);
            SelectObject(hdc, hPenDot);
            SetROP2(hdc, R2_NOTXORPEN);
            aS[h]->draw(hdc);
            A.draw(hdc);
            SetCursor(hCursorMove);
            SetCapture(hWnd);
        }
        if (A.isPointInside(Point(xc, yc)))
        {
            hdc = GetDC(hWnd);
            SelectObject(hdc, hPenDot);
            SetROP2(hdc, R2_NOTXORPEN);
            A.draw(hdc);
            SetCursor(hCursorMove);
            SetCapture(hWnd);
        }
        break;
    case WM_MOUSEMOVE:
        if (GetCapture() == hWnd)
        {
            px = xc; py = yc;
            xc = GET_X_LPARAM(lParam); yc = GET_Y_LPARAM(lParam);
            dx = xc - px; dy = yc - py;
            if (pS->isPointInside(Point(px, py)))
            {
                hdc = GetDC(hWnd);
                SelectObject(hdc, hPenDot);
                SetROP2(hdc, R2_NOTXORPEN);
                aS[h]->draw(hdc);

                aS[h]->move(dx, dy);
                aS[h]->draw(hdc);
            } 
            if (A.isPointInside(Point(px, py)))
            {
                hdc = GetDC(hWnd);
                SelectObject(hdc, penDot);
                SetROP2(hdc, R2_NOTXORPEN);
                A.draw(hdc);
                A.move(dx, dy);
                A.draw(hdc);
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
    case WM_COMMAND:
    {
        wmId = LOWORD(wParam);
        wmEvent = HIWORD(wParam);
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
    case WM_CHAR:
        switch (TCHAR(wParam))
        {
        case '\t':
            if (++h == n) h = 0;
            pS = aS[h];
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case '+':
            pS->scale(1.2);
            //A.scale(1.2);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case '-':
            pS->scale(1 / 1.2);
            //A.scale(1 / 1.2);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 'l':
            pS->rotate(90);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 'r':
            pS->rotate(-90);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        }
    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_LEFT:
            pS->move(-10, 0);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_RIGHT:
            pS->move(10, 0);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_UP:
            pS->move(0, -10);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_DOWN:
            pS->move(0, 10);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        }
    case WM_PAINT:
    {
        //PAINTSTRUCT ps;
        hdc = BeginPaint(hWnd, &ps);
        // TODO: Add any drawing code that uses hdc here...
        HPEN hpen;
        GetClientRect(hWnd, &rt);
        DrawText(hdc, szInfor, lstrlen(szInfor), &rt, DT_CENTER | DT_TOP);
        SelectObject(hdc, hbr);
        pS->draw(hdc);
        swprintf_s(szArea, L"Area of current object (%d/%d): %.2lf - Sum of area of all object: %.2lf", h + 1, n, pS->getArea(), sumOfArea(aS, n));
        DrawText(hdc, szArea, lstrlen(szArea), &rt, DT_CENTER | DT_BOTTOM | DT_SINGLELINE);
        T.mark(hdc);
        A.draw(hdc);
        //C.draw(hdc);
        //B.draw(hdc);  
        //A.intersection(C, hdc);
        SelectObject(hdc, penBorder);
        //A.intersection(pS, hdc);
        if (A.intersection(pS, hdc))
            swprintf_s(szArea, L"Intersect!");
        else
            swprintf_s(szArea, L"Not intersect!");
        DrawText(hdc, szArea, lstrlen(szArea), &rt, DT_RIGHT | DT_TOP);
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        delete[] pS;
        DeleteObject(hbr);
        DeleteObject(hPenDot);
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
