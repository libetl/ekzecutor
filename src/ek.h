#ifndef EK_H
#define EK_H

static HINSTANCE Inst = NULL;
extern HBITMAP spsc, progb;
extern HDC gc, gc2;
extern HMENU menu;

LRESULT CALLBACK SplashProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
void Splash (HINSTANCE hThisInstance, int nFunsterStil);
int WINAPI WinMain (HINSTANCE hThisInstance, HINSTANCE hPrevInstance,
		    LPSTR lpszArgument,int nFunsterStil);

#endif
