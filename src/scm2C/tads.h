#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef TADS_H
#define TADS_H
#define _(a,b) Symbole(a,b)
#define NIL (Symbole(EK_SYMBOLE,"\0"))
#define VAL(a)(a.type==EK_ENTIER ? *(int*)a.valeur : (a.type==EK_SYMBOLE ? *(char**)a.valeur : (a.type==EK_TABLEAU ? *(int**)a.valeur : (a.type==EK_BOOLEEN ? *(bool*)a.valeur : *(P_LISTE*)a.valeur))))
#define EK_ENTIER 0
#define EK_SYMBOLE 1
#define EK_TABLEAU 2
#define EK_LISTE 3
#define EK_BOOLEEN 4
#define FAUX 0
#define VRAI 1

typedef unsigned char bool;

typedef unsigned char ek_type;

typedef struct{
  ek_type type;
  void* valeur;
}symbol;

typedef struct LISTE{
  symbol courant;
  struct LISTE *suivant;
}T_LISTE,*P_LISTE;

bool null(P_LISTE l);
bool equal(symbol a, symbol b);
bool est_entier(symbol a);
bool est_list(symbol a);
bool est_booleen(symbol a);
bool est_tableau(symbol a);
bool est_symbol(symbol a);
symbol Symbole(ek_type type,...);
symbol car(P_LISTE l);
symbol caadr(P_LISTE l);
symbol cadr(P_LISTE l);
symbol caddr(P_LISTE l);
symbol cadddr(P_LISTE l);
symbol caar(P_LISTE l);
symbol read(FILE* fp);
symbol eval(symbol b,symbol a,symbol c);
P_LISTE cdar(P_LISTE l);
P_LISTE cdr(P_LISTE l);
P_LISTE cdadr(P_LISTE l);
P_LISTE cddr(P_LISTE l);
P_LISTE cdddr(P_LISTE l);
P_LISTE list(symbol arg1,...);
P_LISTE cons(symbol a,P_LISTE l);
P_LISTE append(P_LISTE l1,P_LISTE l2);
P_LISTE member(symbol a,P_LISTE l);
int taille_tableau(symbol a);
int vector_ref(symbol a,int ref);
char* Aff(symbol a);
char* affliste(P_LISTE l);
#endif
