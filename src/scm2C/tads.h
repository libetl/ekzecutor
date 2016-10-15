#ifndef TADS_H
#define TADS_H

#define _(a,b) Symbole(a,b)
#define NIL (Symbole(EK_SYMBOLE,"\0"))
#define EK_ENTIER 0
#define EK_SYMBOLE 1
#define EK_TABLEAU 2
#define EK_LISTE 3
#define EK_BOOLEEN 4
#define FAUX 0
#define VRAI 1

typedef unsigned char ek_bool;

typedef unsigned char ek_type;

typedef struct{
  ek_type type;
  void* valeur;
}symbol;

typedef struct LISTE{
  symbol courant;
  struct LISTE *suivant;
}T_LISTE,*P_LISTE;

ek_bool null(P_LISTE l);
ek_bool equal(symbol a, symbol b);
ek_bool est_entier(symbol a);
ek_bool est_list(symbol a);
ek_bool est_booleen(symbol a);
ek_bool est_tableau(symbol a);
ek_bool est_symbol(symbol a);
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
