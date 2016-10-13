#include <stdio.h>
#include <windows.h>
#include "../ek.h"
#include "../ide/ide.h"
#include "../scm2C/tads.h"
#include "interpret.h"
#include "convert.h"

char fstbis[MAX_CHEMIN]="";
int ydraw=2,xdraw=2;
HINSTANCE InstCopy=NULL;

LRESULT CALLBACK ResultatsProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_CREATE:
	{
	  HFONT D;
          D=CreateFont(12,0,0,0,FW_NORMAL,FALSE,FALSE,FALSE,DEFAULT_CHARSET,
	    OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,PROOF_QUALITY,
	    FF_ROMAN,"Verdana");
          gc=GetDC(hwnd);
	  gc2=CreateCompatibleDC(gc);
	  SelectObject(gc,D);
	  SetBkMode(gc,TRANSPARENT);
	  SetTimer(hwnd,0,0,NULL);
	  break;
	}
	case WM_ERASEBKGND:
	{
	  POINT lp[2];
	  RECT rc;
	  int ydrawb=2;
	  rc.top=0;rc.bottom=1024;
	  rc.left=0;rc.right=1280;
	  FillRect(gc, &rc, (HBRUSH) CreateSolidBrush(0xE1AF7D));
	  TextOut(gc,2,ydrawb,"Cliquer sur la croix pour interrompre l'exécution à tout moment.",64);
	  ydrawb=+40;
	  TextOut(gc,xdraw+2,ydrawb,"Fichier d'entrée :",18);
	  TextOut(gc,xdraw+105,ydrawb,fstbis,strlen(fstbis));
	  ydrawb+=15;
	  lp[0].x=0;lp[1].x=rc.right;
	  lp[0].y=71;lp[1].y=71;
	  Polyline(gc,lp,2);
	  lp[0].y=72;lp[1].y=72;
	  Polyline(gc,lp,2);
	  if(ydraw<10)ydraw+=ydrawb+20;
	  break;
	}
	case WM_TIMER:
	{
	  KillTimer(hwnd,0);
  	  k2kp(fstbis);
	  Interpret(&xdraw,&ydraw,NIL,list(NIL),VRAI);
	  xdraw=2;
  	  ydraw=2;
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

void Resultats(char* fst,HWND hwnd,int nFunsterStil)
{
    HWND hwnd2;
    MSG messages2;
    WNDCLASSEX wincl;
    strcpy(fstbis,fst);
    wincl.hInstance = InstCopy;
    wincl.lpszClassName = "EKR";
    wincl.lpfnWndProc = ResultatsProcedure;
    wincl.style = CS_DBLCLKS;
    wincl.cbSize = sizeof (WNDCLASSEX);
    wincl.hIcon = LoadIcon (Inst, MAKEINTRESOURCE(100));
    wincl.hIconSm = LoadIcon (Inst, MAKEINTRESOURCE(100));
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;
    wincl.cbClsExtra = 0;
    wincl.cbWndExtra = 0;
    wincl.hbrBackground = (HBRUSH) (COLOR_BTNFACE+1);
    RegisterClassEx (&wincl);
    hwnd2 = CreateWindowEx (0,"EKR","EKzecuteur - Fenêtre de résultats",WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT,CW_USEDEFAULT,500,400,HWND_DESKTOP,NULL,InstCopy,NULL);
    ShowWindow (hwnd2, nFunsterStil);
    while (GetMessage (&messages2, NULL, 0, 0))
    {
        TranslateMessage(&messages2);
        DispatchMessage(&messages2);
    }
}
