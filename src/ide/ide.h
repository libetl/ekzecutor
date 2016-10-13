#ifndef IDE_H
#define IDE_H

#define MAX_CHEMIN 8192
#define MAX_TAILLE 65536


void Nouveau(HWND hwnd);
void Fermer(HWND hwnd);
void Charger(HWND hwnd);
LRESULT CALLBACK EditeurProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
HMENU FaireMenu(void);
HWND FaireTB(HWND hwnd,HMENU menu,HINSTANCE hThisInstance);
void Editeur(HINSTANCE hThisInstance,int nFunsterStil,HINSTANCE Inst);
#endif
