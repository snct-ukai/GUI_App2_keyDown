// GUI_App1.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "framework.h"
#include "GUI_App1.h"

#define MAX_LOADSTRING 100

// グローバル変数:
HINSTANCE hInst;                                // 現在のインターフェイス
WCHAR szTitle[MAX_LOADSTRING];                  // タイトル バーのテキスト
WCHAR szWindowClass[MAX_LOADSTRING];            // メイン ウィンドウ クラス名

// このコード モジュールに含まれる関数の宣言を転送します:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

void Italy(HDC hdc, int left, int top);
void Guinea(HDC hdc, int left, int top);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: ここにコードを挿入してください。

    // グローバル文字列を初期化する
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_GUIAPP1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // アプリケーション初期化の実行:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GUIAPP1));

    MSG msg;

    // メイン メッセージ ループ:
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
//  関数: MyRegisterClass()
//
//  目的: ウィンドウ クラスを登録します。
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_GUIAPP1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_GUIAPP1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   関数: InitInstance(HINSTANCE, int)
//
//   目的: インスタンス ハンドルを保存して、メイン ウィンドウを作成します
//
//   コメント:
//
//        この関数で、グローバル変数でインスタンス ハンドルを保存し、
//        メイン プログラム ウィンドウを作成および表示します。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // グローバル変数にインスタンス ハンドルを格納する

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
//  関数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的: メイン ウィンドウのメッセージを処理します。
//
//  WM_COMMAND  - アプリケーション メニューの処理
//  WM_PAINT    - メイン ウィンドウを描画する
//  WM_DESTROY  - 中止メッセージを表示して戻る
//
//

HFONT hFont[4];
TCHAR str[100];
static int kx = 100;
static int ky = 100;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE: // ウィンドウ生成メッセージ
        hFont[0] = CreateFont(80, 80, 0, 0, FW_DONTCARE,
            FALSE, FALSE, FALSE, DEFAULT_CHARSET,
            OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
            DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE,
            TEXT("HGｺﾞｼｯｸE")); // フォントオブジェクトを作成

        hFont[1] = CreateFont(60, 60, 0, 0, FW_DONTCARE,
            FALSE, FALSE, FALSE, DEFAULT_CHARSET,
            OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
            DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE,
            TEXT("HG行書体")); // フォントオブジェクトを作成

        hFont[2] = CreateFont(120, 120, 0, 0, FW_DONTCARE,
            FALSE, FALSE, FALSE, DEFAULT_CHARSET,
            OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
            DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE,
            TEXT("HG創英ﾌﾟﾚｾﾞﾝｽEB")); // フォントオブジェクトを作成

        hFont[3] = CreateFont(100, 100, 0, 0, FW_DONTCARE,
            FALSE, FALSE, FALSE, DEFAULT_CHARSET,
            OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
            DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE,
            TEXT("HG創英角ﾎﾟｯﾌﾟ体")); // フォントオブジェクトを作成

        break;

    case WM_CLOSE: // ウィンドウ閉じるメッセージ
        for (int i = 0; i < 4; i++) {
            DeleteObject(hFont[i]);
        } // フォントオブジェクトを削除
        DestroyWindow(hWnd);
        break;

    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 選択されたメニューの解析:
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
        switch (wParam) {
        case VK_LEFT:
            --kx;
            InvalidateRect(hWnd, NULL, TRUE);
            break;

        case VK_RIGHT:
            ++kx;
            InvalidateRect(hWnd, NULL, TRUE);
            break;

        case VK_UP:
            --ky;
            InvalidateRect(hWnd, NULL, TRUE);
            break;

        case VK_DOWN:
            ++ky;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: HDC を使用する描画コードをここに追加してください...
            Italy(hdc, kx, ky);

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

void Italy(HDC hdc, int left, int top) {
    SelectObject(hdc, GetStockObject(DC_PEN)); // PEN（輪郭線）を使う
    SelectObject(hdc, GetStockObject(DC_BRUSH)); // BRUSH（塗り）を使う
    SetDCPenColor(hdc, RGB(0, 147, 68)); // PEN の色
    SetDCBrushColor(hdc, RGB(0, 147, 68)); // BRUSH の色
    Rectangle(hdc, left, top, left + 133, top + 267);
    left += 133;
    SetDCPenColor(hdc, RGB(255, 255, 255)); // PEN の色
    SetDCBrushColor(hdc, RGB(255, 255, 255)); // BRUSH の色
    Rectangle(hdc, left, top, left + 134, top + 267);
    left += 134;
    SetDCPenColor(hdc, RGB(207, 39, 52)); // PEN の色
    SetDCBrushColor(hdc, RGB(207, 39, 52)); // BRUSH の色
    Rectangle(hdc, left, top, left + 133, top + 267);
}

void Guinea(HDC hdc, int left, int top) {
    SelectObject(hdc, GetStockObject(DC_PEN)); // PEN（輪郭線）を使う
    SelectObject(hdc, GetStockObject(DC_BRUSH)); // BRUSH（塗り）を使う
    SetDCPenColor(hdc, RGB(207, 9, 33)); // PEN の色
    SetDCBrushColor(hdc, RGB(207, 9, 33)); // BRUSH の色
    Rectangle(hdc, left, top, left + 133, top + 267);
    left += 133;
    SetDCPenColor(hdc, RGB(252, 210, 15)); // PEN の色
    SetDCBrushColor(hdc, RGB(252, 210, 15)); // BRUSH の色
    Rectangle(hdc, left, top, left + 134, top + 267);
    left += 134;
    SetDCPenColor(hdc, RGB(0, 149, 96)); // PEN の色
    SetDCBrushColor(hdc, RGB(0, 149, 96)); // BRUSH の色
    Rectangle(hdc, left, top, left + 133, top + 267);
}

// バージョン情報ボックスのメッセージ ハンドラーです。
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
