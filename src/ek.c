#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include <time.h>
#include "ide/ide.h"
#include "ek.h"
#include "scm2C/tads.h"
#include "k/interpret.h"

int i=1;
HBITMAP spsc, progb;
HDC gc2;

LRESULT CALLBACK SplashProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_CREATE:
	{
          spsc  = LoadBitmap (Inst, "HB1");
          progb = LoadBitmap (Inst, "HB2");
          gc    = GetDC (hwnd);
	  gc2   = CreateCompatibleDC (gc);
	  SetTimer (hwnd, 0, 0, NULL);
	  break;
	}
	case WM_TIMER:
	{
	  POINT lp[5];
          if(i > 330)
	  {
	    SendMessage (hwnd, WM_CLOSE, 0, 0);
	    Editeur (Inst, 1, Inst);
	    KillTimer (hwnd, 0);
	  }
	  else
	  {
	    lp[0].x = 2;  lp[1].x = 2;  lp[2].x = 329;lp[3].x = 329;lp[4].x = 2;
	    lp[0].y = 202;lp[1].y = 223;lp[2].y = 223;lp[3].y = 202;lp[4].y = 202;
    	    SelectObject(gc2, spsc);
	    BitBlt(gc, 0, 0, 330, 201, gc2, 0, 0, SRCCOPY);
    	    SelectObject(gc2, progb);
	    BitBlt(gc, 2 + i, 203, 32, 20, gc2, 0, 0, SRCCOPY);
	    Polyline(gc, lp, 5);
	    i += 5;
	  }
	  break;
	}
        case WM_DESTROY:
          PostQuitMessage (0);
          break;
        default:
          return DefWindowProc (hwnd, message, wParam, lParam);
    }
    return 0;
}

void Splash (HINSTANCE hThisInstance,int nFunsterStil)
{
    HWND hwnd2;
    MSG messages2;
    WNDCLASSEX wincl;
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = "EK2";
    wincl.lpfnWndProc = SplashProcedure;
    wincl.style = CS_DBLCLKS;
    wincl.cbSize = sizeof (WNDCLASSEX);
    wincl.hIcon = LoadIcon (Inst, MAKEINTRESOURCE(100));
    wincl.hIconSm = LoadIcon (Inst, MAKEINTRESOURCE(100));
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;
    wincl.cbClsExtra = 0;
    wincl.cbWndExtra = 0;
    wincl.hbrBackground = (HBRUSH) (COLOR_BTNFACE + 1);
    RegisterClassEx (&wincl);
    hwnd2 = CreateWindowEx (0, "EK2", "EKzecuteur",
	    DS_MODALFRAME | WS_POPUP | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
            CW_USEDEFAULT, CW_USEDEFAULT, 336, 257, HWND_DESKTOP, NULL, hThisInstance, NULL);
    ShowWindow (hwnd2, nFunsterStil);
    while (GetMessage (&messages2, NULL, 0, 0))
    {
        TranslateMessage(&messages2);
        DispatchMessage(&messages2);
    }
}


int WINAPI WinMain (HINSTANCE hThisInstance, HINSTANCE hPrevInstance,
		    LPSTR lpszArgument, int nFunsterStil)
{
  Inst=hThisInstance;
  srand (time (NULL));
  Splash (hThisInstance, nFunsterStil);
  return 0;
}
