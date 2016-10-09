#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include "ide.h"
#include "../ek.h"
#include "../k/k.h"

char fst[MAX_CHEMIN]="";
static HINSTANCE InstCopy=NULL;

void Nouveau(HWND hwnd)
{
  strcpy(fst,"");
  SendDlgItemMessage(hwnd, 1001, WM_SETFONT,(WPARAM)GetStockObject(ANSI_FIXED_FONT), MAKELPARAM(TRUE, 0));
  SendDlgItemMessage(hwnd, 1001, WM_SETTEXT, 0, (LPARAM)"EKzecuteur : L'interprète du langage K.\r\nTapez votre programme ci-dessous.\r\n\r\nVotre Algorithme:\r\n-----------------\r\n\r\nInitialisation\r\nDifférents cas\r\n\r\nFin\r\n");
  SendDlgItemMessage(hwnd, 1002, SB_SETTEXT, 0, (LPARAM)"Je vous conseille de travailler avec l'aide sur l'Internet : menu Aide / Comment programmer.");
}

void Fermer(HWND hwnd)
{
  strcpy(fst,"");
  SendDlgItemMessage(hwnd, 1001, WM_SETTEXT, 0, (LPARAM)"");
  SendDlgItemMessage(hwnd, 1002, SB_SETTEXT, 0, (LPARAM)"La zone de texte est vide : cela signifie que vous pouvez commencer a créer un algorithme sans amorce, ce que je vous deconseille.");
}

char* LancerOFN(HWND hwnd,DWORD drapeaux,char* titre)
{
  char fstmp[MAX_CHEMIN]="";
  OPENFILENAME ofn;
  ZeroMemory(&ofn,sizeof(ofn));
  ofn.lStructSize=sizeof(ofn);
  ofn.lpstrTitle=titre;
  ofn.hwndOwner=hwnd;
  ofn.lpstrFilter="Fichier en langage K (*.k)\0*.k\0Langage semi-interprété (*.kp)\0*.kp\0\0";
  ofn.lpstrFile=fstmp;
  ofn.nMaxFile=MAX_CHEMIN;
  ofn.lpstrDefExt="mp3";
  ofn.Flags=drapeaux;
  GetOpenFileName(&ofn);
  return ofn.lpstrFile;
}

void Charger(HWND hwnd)
{
  HANDLE fp;char str1[MAX_CHEMIN]="",strfic[MAX_TAILLE]="";
  DWORD b=0;
  strcpy(str1,LancerOFN(hwnd,OFN_EXPLORER|OFN_LONGNAMES|OFN_FILEMUSTEXIST,"Charger un fichier en langage K :"));
  if(str1[0]!='\0')
  {
    strcpy(fst,str1);
    fp=CreateFile(fst,GENERIC_READ|GENERIC_WRITE,
    FILE_SHARE_READ|FILE_SHARE_WRITE|FILE_SHARE_DELETE,NULL,OPEN_ALWAYS,
    FILE_ATTRIBUTE_NORMAL|FILE_ATTRIBUTE_READONLY|FILE_ATTRIBUTE_TEMPORARY,NULL);
    ReadFile(fp,strfic,MAX_TAILLE,&b,NULL);
    SendDlgItemMessage(hwnd, 1001, WM_SETTEXT, 0, (LPARAM)strfic);
    SendDlgItemMessage(hwnd, 1002, SB_SETTEXT, 0, (LPARAM)"Fichier Ouvert.");
  }
}

void Enregistrer(HWND hwnd,char forcer)
{
  HANDLE fp;char str1[MAX_CHEMIN]="",str2[MAX_TAILLE]="";
  if(fst[0]=='\0' || forcer==1)
    strcpy(str1,LancerOFN(hwnd,OFN_EXPLORER|OFN_LONGNAMES,"Sauver ce fichier K comme..."));
  if(fst[0]!='\0' || str1[0]!='\0')
  {
    DWORD b=0;
    if(str1[0]!='\0')strcpy(fst,str1);
    SendDlgItemMessage(hwnd, 1001, WM_GETTEXT, MAX_TAILLE,(LPARAM)str2);
    fp=CreateFile(fst,GENERIC_READ|GENERIC_WRITE,
    FILE_SHARE_READ|FILE_SHARE_WRITE|FILE_SHARE_DELETE,NULL,CREATE_ALWAYS,
    FILE_ATTRIBUTE_NORMAL,NULL);
    WriteFile(fp,str2,strlen(str2),&b,NULL);
    SendDlgItemMessage(hwnd, 1002, SB_SETTEXT, 0, (LPARAM)"Fait.");
  }
}


BOOL CALLBACK Apropos(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam)
{
  switch(message)
  {
    case WM_INITDIALOG:break;
    case WM_CLOSE:
    case WM_DESTROY:
      EndDialog(hwnd,FALSE);
      PostQuitMessage(0);
      break;
    case WM_COMMAND:
      if(LOWORD(wParam)==301)
      {
	EndDialog(hwnd,FALSE);
	PostQuitMessage(0);
      }
      break;
    default:break;
  }
  return 0;
}

LRESULT CALLBACK EditeurProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_CREATE:
	{
	  int iStatusWidths[] = {-1};
	  CreateWindow("EDIT", "EKED",
               WS_CHILD | WS_VISIBLE | WS_HSCROLL | WS_VSCROLL | ES_MULTILINE | ES_WANTRETURN,
               1, 32, 790, 576,
               hwnd, (HMENU)1001,InstCopy, NULL);
	  Nouveau(hwnd);
 	  CreateWindowEx(0, STATUSCLASSNAME, NULL,
          WS_CHILD|WS_VISIBLE|SBARS_SIZEGRIP, 0, 0, 0, 0,hwnd, (HMENU)1002, InstCopy, NULL);
          SendDlgItemMessage(hwnd, 1002, SB_SETPARTS, 1, (LPARAM)iStatusWidths);
          SendDlgItemMessage(hwnd, 1002, SB_SETTEXT, 0, (LPARAM)"EKzecuteur prêt.");
	  break;
	}
	case WM_COMMAND:
	  switch(wParam)
	  {
	    case 1:
	    case 201:Nouveau(hwnd);break;
	    case 2:
	    case 202:Charger(hwnd);break;
	    case 3:
	    case 203:Enregistrer(hwnd,0);break;
	    case 204:Enregistrer(hwnd,1);break;
	    case 4:{
	      char tot[MAX_TAILLE]="";
	      SendDlgItemMessage(hwnd, 1001, WM_GETTEXT, MAX_TAILLE,(LPARAM)tot);
	      strcat(tot,"\r\nInitialisation\r\nDifférents cas\r\nFin\r\n");
	      SendDlgItemMessage(hwnd, 1001, WM_SETTEXT, 0,(LPARAM)tot);
	      break;}
	    case 221:
	    case 5:if(strcmp(fst,"")!=0)Resultats(fst,hwnd,1);break;
	    case 205:Fermer(hwnd);break;
	    case 231:ShellExecute(hwnd,"open","http://libe4.free.fr/langk/", NULL, NULL, SW_SHOWNORMAL);break;
	    case 232:ShellExecute(hwnd,"open","http://libe4.free.fr/langk/ek.html", NULL, NULL, SW_SHOWNORMAL);break;
	    case 233:ShellExecute(hwnd,"open","http://www.unice.fr/", NULL, NULL, SW_SHOWNORMAL);break;
	    case 234:{
	      MSG message;
	      DialogBox(InstCopy,(LPCTSTR)300,hwnd,(DLGPROC)Apropos);
	      ShowWindow(hwnd,SW_SHOW);
	      while(GetMessage(&message,NULL,0,0))
	      {
	        TranslateMessage(&message);
	        DispatchMessage(&message);
	      }
	      break;
	    }
	    case 6:remove("ctmp.kp");break;
	    case 206:
	    case 7:SendMessage(hwnd, WM_CLOSE, 0, 0);
	    default:break;
	  }
	  break;
        case WM_SIZE:
         if(wParam != SIZE_MINIMIZED)
            MoveWindow(GetDlgItem(hwnd, 1001), 1, 32, LOWORD(lParam),
               HIWORD(lParam)-55, TRUE);
            MoveWindow(GetDlgItem(hwnd, 1002), 0, 0, LOWORD(lParam),
               HIWORD(lParam), TRUE);
	break;
	case WM_CLOSE:
	  if(MessageBox(hwnd,"Ceci fermera l'EKzecuteur.","Quitter EKzecuteur",MB_OKCANCEL|MB_ICONQUESTION)==IDOK)
	    PostQuitMessage(0);
      	  break;
        case WM_DESTROY:
          PostQuitMessage (0);
          break;
        default:
          return DefWindowProc (hwnd, message, wParam, lParam);
    }
    return 0;
}

HMENU FaireMenu(void)
{
   HMENU menu;
   menu=LoadMenu(InstCopy,MAKEINTRESOURCE(200));
   return menu;
}

HWND FaireTB(HWND hwnd,HMENU menu,HINSTANCE hThisInstance)
{
   TBBUTTON tbb[8];
   TBADDBITMAP tbab;
   HWND hTB;
   RECT rc;
   char i;
   ZeroMemory(tbb, sizeof(tbb));
   hTB = CreateWindowEx(0, TOOLBARCLASSNAME, (LPSTR) NULL, 
        WS_CHILD|WS_VISIBLE|TBSTYLE_TOOLTIPS|TBSTYLE_WRAPABLE,0,0,0,0, hwnd, 
        (HMENU) menu, hThisInstance, NULL);
   SendMessage(hTB, TB_BUTTONSTRUCTSIZE, (WPARAM) sizeof(TBBUTTON), 0); 
   SendMessage(hTB, TB_SETBITMAPSIZE, (WPARAM)0, (LPARAM)MAKELONG(20, 20));
   for (i=1;i<=8;i++)
   {
     tbab.hInst = (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE); 
     tbab.nID   = 100+i; 
     SendMessage(hTB, TB_ADDBITMAP, (WPARAM) 1, (LPARAM) &tbab);
     GetWindowRect(hwnd,&rc);
     tbb[i-1].iBitmap = i; 
     tbb[i-1].idCommand = i; 
     tbb[i-1].fsState = TBSTATE_ENABLED; 
     tbb[i-1].fsStyle = TBSTYLE_BUTTON; 
     tbb[i-1].iString = 0; 
   }
   SendMessage(hTB, TB_ADDBUTTONS, i-2, (LPARAM)&tbb);
   SendMessage(hTB, TB_AUTOSIZE, 0, 0);
   return hTB;
}

void Editeur(HINSTANCE hThisInstance,int nFunsterStil,HINSTANCE Inst)
{
  HMENU menu=FaireMenu();
  HWND hwnd2,htb;
  MSG messages;
  WNDCLASSEX wincl;
  INITCOMMONCONTROLSEX icce;
  InstCopy=Inst;
  icce.dwSize=sizeof(INITCOMMONCONTROLSEX);
  icce.dwICC=ICC_BAR_CLASSES;
  InitCommonControlsEx(&icce);
  wincl.hInstance = hThisInstance;
  wincl.lpszClassName = "EK";
  wincl.lpfnWndProc = EditeurProcedure;
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
  hwnd2 = CreateWindowEx (0,"EK","EKzecuteur",WS_OVERLAPPEDWINDOW,
          CW_USEDEFAULT,CW_USEDEFAULT,800,686,HWND_DESKTOP,menu,hThisInstance,NULL);
  htb=FaireTB(hwnd2,menu,hThisInstance);
  ShowWindow (hwnd2, nFunsterStil);
  UpdateWindow(hwnd2);
  while (GetMessage (&messages, NULL, 0, 0))
  {
      TranslateMessage(&messages);
      DispatchMessage(&messages);
  }
}
