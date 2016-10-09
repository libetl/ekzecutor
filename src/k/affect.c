#include <stdio.h>
#include "../scm2C/tads.h"
#include "args.h"
#include <windows.h>
int* vector_swap(int** T,int i,int j)
{
  int tmp;
  tmp=(*T)[i];
  (*T)[i]=(*T)[j];
  (*T)[j]=tmp;
  return *T;
}

void trier(int* T,int i,int j)
{
  int a,b;
  for(a=0;a<=j;a++)
  {
    for(b=0;b<j;b++)
    {
      if(T[a]<T[b])vector_swap(&T,a,b);
    }
  }
}

P_LISTE cut(P_LISTE l,P_LISTE l1,P_LISTE l2)
{
  if(null(l))return list(_(EK_LISTE,l1),_(EK_LISTE,l2),NIL);
  if(null(cdr(l)))return list(_(EK_LISTE,cons(car(l),l1)),_(EK_LISTE,l2),NIL);
  return cut(cddr(l),cons(car(l),l1),cons(cadr(l),l2));
}

P_LISTE fus(P_LISTE lt1,P_LISTE lt2)
{
  if(null(lt1))return lt2;
  if(null(lt2))return lt1;
  if(*(int*)car(lt1).valeur < *(int*)car(lt2).valeur)return cons(car(lt1),fus(cdr(lt1),lt2));
  return cons(car(lt2),fus(lt1,cdr(lt2)));
}

P_LISTE LSort(P_LISTE l)
{
  if(null(l) || null(cdr(l)))return l;
  else{
    P_LISTE d;
    d=cut(l,list(NIL),list(NIL));
    return fus(LSort(*(P_LISTE*)car(d).valeur),LSort(*(P_LISTE*)cadr(d).valeur));
  }
}

P_LISTE append_val(P_LISTE liste,symbol elem)
{
  if(null(liste))return cons(elem,liste);
  return cons(car(liste),append_val(cdr(liste),elem));
}

P_LISTE replace_last(P_LISTE accu,symbol elem)
{
  if(null(cdr(accu)))return cons(elem,list(NIL));
  return cons(car(accu),replace_last(cdr(accu),elem));
}

symbol last(P_LISTE liste)
{
  if(null(liste))return _(EK_ENTIER,0);
  if(null(cdr(liste)))return car(liste);
  return last(cdr(liste));
}

P_LISTE CheckEmptiness(P_LISTE Vals)
{
  if(null(Vals))return Vals;
  if(equal(car(Vals),_(EK_SYMBOLE,"vide")))return cons(NIL,CheckEmptiness(cdr(Vals)));
  return cons(car(Vals),CheckEmptiness(cdr(Vals)));
}

P_LISTE Allwithout(symbol sym,P_LISTE L)
{
  if(null(L))return L;
  if(equal(_(EK_LISTE,L),_(EK_LISTE,list(_(EK_SYMBOLE,"Undefined_case"),NIL))))return L;
  if(null(cdr(L)))return L;
  if(equal(sym,car(L)) && null(cddr(L)))return list(NIL);
  if(equal(sym,car(L)))return append(cdddr(L),list(caddr(L),NIL));
  if(equal(sym,cadr(L)))return append(cdddr(L),list(car(L),NIL));
  return cons(car(L),Allwithout(sym,cdr(L)));
}

P_LISTE stack(symbol func,P_LISTE args,P_LISTE vals,P_LISTE func2)
{
  if(!null(func2) && !null(cdr(func2)))
    return cons(FindValueOf(car(func2),func,args,vals,0),cons(cadr(func2),stack(func,args,vals,cddr(func2))));
  return list(NIL);
}

symbol pops(symbol res,P_LISTE Accu)
{
  if(null(Accu))return res;
  if(null(cddr(Accu)) && equal(cadr(Accu),_(EK_SYMBOLE,"&")) && equal(res,_(EK_SYMBOLE,"vide")))return _(EK_LISTE,cons(car(Accu),list(NIL)));
  if(null(cddr(Accu)) && equal(cadr(Accu),_(EK_SYMBOLE,"&")))return _(EK_LISTE,cons(car(Accu),*(P_LISTE*)res.valeur));
  if(null(cddr(Accu)))return eval(cadr(Accu),car(Accu),res);
  if(equal(cadr(Accu),_(EK_SYMBOLE,"&")))
  {
    P_LISTE a;
    a=cons(car(Accu),*(P_LISTE*)pops(res,cddr(Accu)).valeur);
    return _(EK_LISTE,a);
  }
  return pops(res,cons(eval(cadr(Accu),car(Accu),caddr(Accu)),cdddr(Accu)));
}

void SearchFor(FILE* fp,symbol sym)
{
  symbol a;
  a=read(fp);
  if(feof(fp)){rewind(fp);SearchFor(fp,sym);}
  if(!equal(a,sym))SearchFor(fp,sym);
}
