#include "Long_Nguyen Project OOP.h"
#include "framework.h"
#include "ClassHinh.h"
#include "DaGiac.h"
#include "TuGiac.h"
#include "TamGiac.h"
#include "Ellipse.h"

#define MAX_LOADSTRING 100


HINSTANCE hInst;
WCHAR szTitle[MAX_LOADSTRING];
WCHAR szWindowClass[MAX_LOADSTRING];


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


	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_LONGNGUYENPROJECTOOP, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);


	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LONGNGUYENPROJECTOOP));

	MSG msg;


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




ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LONGNGUYENPROJECTOOP));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_LONGNGUYENPROJECTOOP);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}


BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance;
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


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	static wchar_t szItsMessage[1000] = L"";
	static wchar_t szInfor[1000] = L"";
	//brush and pen
	static HBRUSH hbr1, hbr2; // mẫu tô
	static HPEN hPenDot, penBorder1, penBorder2, penBorder; //nét vẽ
	//cursor
	static HCURSOR hCursorMove, hCursorCross;
	//bien

	static int xc, yc, px, py;

	int dx, dy;
	RECT rt;
	//doituong
	static Diem p[3] = { Diem(200,200), Diem(100, 600), Diem(600,450) };
	static Diem p2[3] = { Diem(400,200), Diem(600, 450), Diem(1000,450) };
	static Diem plg1[5] = { Diem(400,200), Diem(600, 300), Diem(450, 350), Diem(300, 400), Diem(200, 350) };
	static Diem plg2[6] = { Diem(300,200), Diem(750, 250), Diem(800, 300), Diem(600, 400), Diem(400, 450), Diem(200, 350) };

	static Hinh* aS[] =
	{
		new DaGiac(5, plg1),
		new Hcn(200, 100, 300, 200),
		new Hvuong(100, 100, 200),
		new TamGiac(p),
		new Elipse(300,250,200,100),
		new Htron(200, 200, 150),

	};
	static Hinh* aS2[] =
	{
		new DaGiac(6, plg2),
		new Hcn(600, 100, 300, 200),
		new Hvuong(700, 100, 200),
		new TamGiac(p2),
		new Elipse(800,250,200,100),
		new Htron(600, 200, 150)

	};
	static int h = 0, h2 = 0;
	const int n = sizeof(aS) / sizeof(aS[0]), n2 = sizeof(aS2) / sizeof(aS2[0]);
	static Hinh* pS = aS[h];
	static Hinh* pS2 = aS2[h2];
	switch (message)
	{
	case WM_CREATE:
		GetClientRect(hWnd, &rt);
		hbr1 = CreateSolidBrush(RGB(204, 153, 255));// tô màu tím cho hình 1
		hbr2 = CreateSolidBrush(RGB(255, 255, 128));// tô màu vàng cho hình 2
		hCursorMove = LoadCursor(NULL, IDC_SIZEALL);
		hCursorCross = LoadCursor(NULL, IDC_CROSS);
		penBorder = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));// tô phần viền cho phần giao
		penBorder1 = CreatePen(PS_SOLID, 2, RGB(89, 0, 179));// tô phần viền cho hình 1
		penBorder2 = CreatePen(PS_SOLID, 2, RGB(128, 128, 0));// tô phần viền cho hình 2
		break;
	case WM_LBUTTONDOWN:
		xc = GET_X_LPARAM(lParam); yc = GET_Y_LPARAM(lParam);
		if (aS[h]->DiemTrongHinh(Diem(xc, yc)))
		{
			hdc = GetDC(hWnd);
			SelectObject(hdc, hPenDot);
			SetROP2(hdc, R2_NOTXORPEN);
			aS[h]->Ve(hdc);
			SetCursor(hCursorMove);
			SetCapture(hWnd);
		}
		else
			if (aS2[h2]->DiemTrongHinh(Diem(xc, yc)))
			{
				hdc = GetDC(hWnd);
				SelectObject(hdc, hPenDot);
				SetROP2(hdc, R2_NOTXORPEN);
				aS2[h2]->Ve(hdc);
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
			if (pS->DiemTrongHinh(Diem(px, py)))
			{
				hdc = GetDC(hWnd);
				SelectObject(hdc, hPenDot);
				SetROP2(hdc, R2_NOTXORPEN);
				aS[h]->Ve(hdc);

				aS[h]->dichuyen(dx, dy);
				aS[h]->Ve(hdc);
			}
			else
				if (pS2->DiemTrongHinh(Diem(px, py)))
				{
					hdc = GetDC(hWnd);
					SelectObject(hdc, hPenDot);
					SetROP2(hdc, R2_NOTXORPEN);
					aS2[h2]->Ve(hdc);
					aS2[h2]->dichuyen(dx, dy);
					aS2[h2]->Ve(hdc);
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
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_TAB:
			if (GetAsyncKeyState(VK_CONTROL))
			{
				if (++h2 == n2) h2 = 0;
				pS2 = aS2[h2];
				InvalidateRect(hWnd, NULL, TRUE);
				break;
			}
			else
			{
				if (++h == n) h = 0;
				pS = aS[h];
				InvalidateRect(hWnd, NULL, TRUE);
				break;
			}
		case VK_OEM_PLUS:
			if (GetAsyncKeyState(VK_CONTROL))
			{
				pS2->phongto_thunho(1.2);
				InvalidateRect(hWnd, NULL, TRUE);
				break;
			}
			else
			{
				pS->phongto_thunho(1.2);
				InvalidateRect(hWnd, NULL, TRUE);
				break;
			}
		case 0x4C:
			if (GetAsyncKeyState(VK_CONTROL))
			{
				pS2->xoay(-45);
				InvalidateRect(hWnd, NULL, TRUE);
				break;
			}
			else
			{
				pS->xoay(-45);
				InvalidateRect(hWnd, NULL, TRUE);
				break;
			}
		case 0x52:
			if (GetAsyncKeyState(VK_CONTROL))
			{
				pS2->xoay(45);
				InvalidateRect(hWnd, NULL, TRUE);
				break;
			}
			else
			{
				pS->xoay(45);
				InvalidateRect(hWnd, NULL, TRUE);
				break;
			}
		case VK_OEM_MINUS:
			if (GetAsyncKeyState(VK_CONTROL))
			{
				pS2->phongto_thunho(1 / 1.2);
				InvalidateRect(hWnd, NULL, TRUE);
				break;
			}
			else
			{
				pS->phongto_thunho(1 / 1.2);
				InvalidateRect(hWnd, NULL, TRUE);
				break;
			}
		case VK_LEFT:
			if (GetAsyncKeyState(VK_CONTROL))
			{
				pS2->dichuyen(-10, 0);
				InvalidateRect(hWnd, NULL, TRUE);
				break;
			}
			else
			{
				pS->dichuyen(-10, 0);
				InvalidateRect(hWnd, NULL, TRUE);
				break;
			}
		case VK_RIGHT:
			if (GetAsyncKeyState(VK_CONTROL))
			{
				pS2->dichuyen(10, 0);
				InvalidateRect(hWnd, NULL, TRUE);
				break;
			}
			else
			{
				pS->dichuyen(10, 0);
				InvalidateRect(hWnd, NULL, TRUE);
				break;
			}
		case VK_UP:
			if (GetAsyncKeyState(VK_CONTROL))
			{
				pS2->dichuyen(0, -10);
				InvalidateRect(hWnd, NULL, TRUE);
				break;
			}
			else {
				pS->dichuyen(0, -10);
				InvalidateRect(hWnd, NULL, TRUE);
				break;
			}
		case VK_DOWN:
			if (GetAsyncKeyState(VK_CONTROL))
			{
				pS2->dichuyen(0, 10);
				InvalidateRect(hWnd, NULL, TRUE);
				break;
			}
			else {
				pS->dichuyen(0, 10);
				InvalidateRect(hWnd, NULL, TRUE);
				break;
			}
		}
	case WM_PAINT:
	{
		//PAINTSTRUCT ps;
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code that uses hdc here...
		HPEN hpen;
		GetClientRect(hWnd, &rt);
		swprintf_s(szInfor, L"Phím '🡡🡣🡠🡢' (Di chuyển)\nPhím 'Tab' (Đổi hình màu tím)\nPhím '-' (Thu nhỏ)\nPhím '+' (Phóng to)\nPhím 'l' (xoay trái)\nPhím 'r' (xoay phải)\nPhím 'Ctrl + key' (Thay đổi hình màu vàng)");
		DrawText(hdc, szInfor, lstrlen(szInfor), &rt, DT_LEFT);
		//DrawText(hdc, szInfor, lstrlen(szInfor), &rt, DT_CENTER | DT_BOTTOM | DT_SINGLELINE);
		SelectObject(hdc, hbr1);
		SelectObject(hdc, penBorder1);
		pS->Ve(hdc);
		SelectObject(hdc, hbr2);
		SelectObject(hdc, penBorder2);
		pS2->Ve(hdc);
		SelectObject(hdc, penBorder);
		if (pS2->PhanGiao(pS, hdc))
			swprintf_s(szItsMessage, L"Giao nhau");
		else
			swprintf_s(szItsMessage, L"Không Giao nhau");
		DrawText(hdc, szItsMessage, lstrlen(szItsMessage), &rt, DT_CENTER | DT_TOP);
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		delete[] pS;
		delete[] pS2;
		DeleteObject(hbr1);
		DeleteObject(hbr2);
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
