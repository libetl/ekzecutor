#include "../scm2C/tads.h"
#include "affect.h"
#include "args.h"
#include "interpret.h"
#define RANDOMMAX 50

P_LISTE ackArgs(P_LISTE args,P_LISTE vals,int* xdraw,int* ydraw)
{
  if(null(args) || null(vals))return vals;
  if((equal(car(args),_(EK_SYMBOLE,"T")) && equal(car(vals),_(EK_SYMBOLE,"T"))) ||
     (equal(car(args),_(EK_SYMBOLE,"T1")) && equal(car(vals),_(EK_SYMBOLE,"T1"))) ||
     (equal(car(args),_(EK_SYMBOLE,"T2")) && equal(car(vals),_(EK_SYMBOLE,"T2"))))
  {
    int *a,i;
    symbol *b;
    a=malloc(sizeof(int));
    b=malloc(sizeof(symbol));
    for(i=0;i<11;i++)
    {
      a=(int*)realloc(a,(i+1)*sizeof(int));
      a[i]=rand()%RANDOMMAX;
    }
    a=(int*)realloc(a,(i+1)*sizeof(int));
    a[11]=-1;
    *b=_(EK_TABLEAU,a);
    return cons(*b,ackArgs(cdr(args),cdr(vals),xdraw,ydraw));
  }
  if((equal(car(args),_(EK_SYMBOLE,"T")) && equal(car(vals),_(EK_SYMBOLE,"Trié")) && equal(cadr(vals),_(EK_LISTE,list(_(EK_SYMBOLE,"T"),NIL)))) ||
     (equal(car(args),_(EK_SYMBOLE,"T1")) && equal(car(vals),_(EK_SYMBOLE,"Trié")) && equal(cadr(vals),_(EK_LISTE,list(_(EK_SYMBOLE,"T1"),NIL)))) ||
     (equal(car(args),_(EK_SYMBOLE,"T2")) && equal(car(vals),_(EK_SYMBOLE,"Trié")) && equal(cadr(vals),_(EK_LISTE,list(_(EK_SYMBOLE,"T2"),NIL)))))
  {
    int *a,i;
    symbol *b;
    a=malloc(sizeof(int));
    b=malloc(sizeof(symbol));
    for(i=0;i<11;i++)
    {
      a=(int*)realloc(a,(i+1)*sizeof(int));
      a[i]=rand()%RANDOMMAX;
    }
    a=(int*)realloc(a,(i+1)*sizeof(int));
    a[11]=-1;
    trier(a,0,10);
    *b=_(EK_TABLEAU,a);
    return cons(*b,ackArgs(cdr(args),cddr(vals),xdraw,ydraw));
  }
  if((equal(car(args),_(EK_SYMBOLE,"L")) && equal(car(vals),_(EK_SYMBOLE,"Trié")) && equal(cadr(vals),_(EK_LISTE,list(_(EK_SYMBOLE,"L"),NIL)))) ||
     (equal(car(args),_(EK_SYMBOLE,"L1")) && equal(car(vals),_(EK_SYMBOLE,"Trié")) && equal(cadr(vals),_(EK_LISTE,list(_(EK_SYMBOLE,"L1"),NIL)))) ||
     (equal(car(args),_(EK_SYMBOLE,"L2")) && equal(car(vals),_(EK_SYMBOLE,"Trié")) && equal(cadr(vals),_(EK_LISTE,list(_(EK_SYMBOLE,"L2"),NIL)))))
    return cons(_(EK_LISTE,LSort(list(_(EK_ENTIER,rand()%RANDOMMAX),_(EK_ENTIER,rand()%RANDOMMAX),_(EK_ENTIER,rand()%RANDOMMAX),_(EK_ENTIER,rand()%RANDOMMAX),_(EK_ENTIER,rand()%RANDOMMAX),_(EK_ENTIER,rand()%RANDOMMAX),_(EK_ENTIER,rand()%RANDOMMAX),_(EK_ENTIER,rand()%RANDOMMAX),_(EK_ENTIER,rand()%RANDOMMAX),_(EK_ENTIER,rand()%RANDOMMAX),_(EK_ENTIER,rand()%RANDOMMAX),NIL))),ackArgs(cdr(args),cddr(vals),xdraw,ydraw)); 
  if((equal(car(args),_(EK_SYMBOLE,"L")) && equal(car(vals),_(EK_SYMBOLE,"c")) && equal(cadr(vals),_(EK_SYMBOLE,"&")) && equal(caddr(vals),_(EK_SYMBOLE,"L"))) ||
     (equal(car(args),_(EK_SYMBOLE,"L1")) && equal(car(vals),_(EK_SYMBOLE,"c1")) && equal(cadr(vals),_(EK_SYMBOLE,"&")) && equal(caddr(vals),_(EK_SYMBOLE,"L1"))) ||
     (equal(car(args),_(EK_SYMBOLE,"L2")) && equal(car(vals),_(EK_SYMBOLE,"c2")) && equal(cadr(vals),_(EK_SYMBOLE,"&")) && equal(caddr(vals),_(EK_SYMBOLE,"L2"))))
  {
    P_LISTE a;
    a=list(_(EK_ENTIER,rand()%RANDOMMAX),_(EK_ENTIER,rand()%RANDOMMAX),_(EK_ENTIER,rand()%RANDOMMAX),_(EK_ENTIER,rand()%RANDOMMAX),_(EK_ENTIER,rand()%RANDOMMAX),_(EK_ENTIER,rand()%RANDOMMAX),_(EK_ENTIER,rand()%RANDOMMAX),_(EK_ENTIER,rand()%RANDOMMAX),_(EK_ENTIER,rand()%RANDOMMAX),_(EK_ENTIER,rand()%RANDOMMAX),_(EK_ENTIER,rand()%RANDOMMAX),NIL);
    return cons(_(EK_LISTE,a),ackArgs(cdr(args),cdddr(vals),xdraw,ydraw));
  }
  if((equal(car(args),_(EK_SYMBOLE,"L")) && equal(car(vals),_(EK_SYMBOLE,"L"))) ||
     (equal(car(args),_(EK_SYMBOLE,"L1")) && equal(car(vals),_(EK_SYMBOLE,"L1"))) ||
     (equal(car(args),_(EK_SYMBOLE,"L2")) && equal(car(vals),_(EK_SYMBOLE,"L2"))))
    return cons(_(EK_LISTE,list(_(EK_ENTIER,rand()%RANDOMMAX),_(EK_ENTIER,rand()%RANDOMMAX),_(EK_ENTIER,rand()%RANDOMMAX),_(EK_ENTIER,rand()%RANDOMMAX),_(EK_ENTIER,rand()%RANDOMMAX),_(EK_ENTIER,rand()%RANDOMMAX),_(EK_ENTIER,rand()%RANDOMMAX),_(EK_ENTIER,rand()%RANDOMMAX),_(EK_ENTIER,rand()%RANDOMMAX),_(EK_ENTIER,rand()%RANDOMMAX),NIL)),ackArgs(cdr(args),cdr(vals),xdraw,ydraw));
  if((equal(car(args),_(EK_SYMBOLE,"L")) || equal(car(args),_(EK_SYMBOLE,"L1")) || equal(car(args),_(EK_SYMBOLE,"L2"))) && equal(car(vals),_(EK_SYMBOLE,"vide")))
    return cons(_(EK_LISTE,list(NIL)),ackArgs(cdr(args),cdr(vals),xdraw,ydraw));
  if(equal(car(vals),_(EK_SYMBOLE,"|T|")) || equal(car(vals),_(EK_SYMBOLE,"|T1|")) || equal(car(vals),_(EK_SYMBOLE,"|T2|")) || equal(car(vals),_(EK_SYMBOLE,"|L|")) || equal(car(vals),_(EK_SYMBOLE,"|L1|")) || equal(car(vals),_(EK_SYMBOLE,"|L2|")))
    return cons(_(EK_ENTIER,11),ackArgs(cdr(args),cdr(vals),xdraw,ydraw));
  if(!(equal(car(vals),_(EK_SYMBOLE,"T")) || equal(car(vals),_(EK_SYMBOLE,"T1")) || equal(car(vals),_(EK_SYMBOLE,"T2")) || equal(car(vals),_(EK_SYMBOLE,"L")) || equal(car(vals),_(EK_SYMBOLE,"L1")) || equal(car(vals),_(EK_SYMBOLE,"L2"))))
  {
    if(est_symbol(car(vals)) && est_list(cadr(vals)))
      return cons(Interpret(xdraw,ydraw,car(vals),*(P_LISTE*)cadr(vals).valeur,FAUX),ackArgs(cdr(args),cddr(vals),xdraw,ydraw));
    if(est_symbol(car(vals)) && (null(cadr(vals).valeur) || !(est_list(cadr(vals)))))
      return cons(_(EK_ENTIER,rand()%RANDOMMAX),ackArgs(cdr(args),cdr(vals),xdraw,ydraw));
  }
  if(est_symbol(car(vals)) && !equal(car(vals),_(EK_SYMBOLE,"T")) && !equal(car(vals),_(EK_SYMBOLE,"T1")) && !equal(car(vals),_(EK_SYMBOLE,"T2")) && est_list(cadr(vals)))
  return cons(Interpret(xdraw,ydraw,car(vals),*(P_LISTE*)cadr(vals).valeur,FAUX),ackArgs(cdr(args),cddr(vals),xdraw,ydraw));
  if(est_symbol(car(vals)) &&  !equal(car(vals),_(EK_SYMBOLE,"T")) && !equal(car(vals),_(EK_SYMBOLE,"T1")) && !equal(car(vals),_(EK_SYMBOLE,"T2")) && est_list(cadr(vals)))
  return cons(_(EK_ENTIER,rand()%RANDOMMAX),ackArgs(cdr(args),cdr(vals),xdraw,ydraw));
  return cons(car(vals),ackArgs(cdr(args),cdr(vals),xdraw,ydraw));
}

P_LISTE InitTableValues(P_LISTE tab,P_LISTE vals)
{
  if(null(vals))return vals;
  if(null(tab))return vals;
  if(!(est_tableau(car(tab))))InitTableValues(cdr(tab),vals);
  if((equal(car(vals),_(EK_SYMBOLE,"T")) || equal(car(vals),_(EK_SYMBOLE,"T1")) || equal(car(vals),_(EK_SYMBOLE,"T2"))))
  return cons(_(EK_ENTIER,vector_ref(car(tab),*(int*)caadr(vals).valeur-1)),InitTableValues(tab,cddr(vals)));
  return cons(car(vals),InitTableValues(tab,cdr(vals)));
}

P_LISTE InitListValues(P_LISTE lst,P_LISTE args,P_LISTE vals)
{
  if(null(vals))return vals;
  if(null(lst))return vals;
  if(null(args))return vals;
  if(!(est_list(car(lst))))return InitListValues(cdr(lst),cdr(args),vals);
  if(equal(car(vals),_(EK_SYMBOLE,"c")))return cons(caar(lst),InitListValues(lst,args,cdr(vals)));
  if(equal(car(vals),_(EK_SYMBOLE,"c1")) && equal(car(args),_(EK_SYMBOLE,"L1")))return cons(caar(lst),InitListValues(lst,args,cdr(vals)));
  if(equal(car(vals),_(EK_SYMBOLE,"c2")) && equal(car(args),_(EK_SYMBOLE,"L2")))return cons(caar(lst),InitListValues(lst,args,cdr(vals)));
  return cons(car(vals),InitListValues(lst,args,cdr(vals)));
}

P_LISTE Transform_vals(P_LISTE vals,symbol func,P_LISTE arg1,P_LISTE val1,int* xdraw,int* ydraw)
{
  if(null(vals))return list(NIL);
  if(equal(_(EK_LISTE,vals),_(EK_LISTE,list(_(EK_SYMBOLE,"$"),NIL))))return val1;
  if(equal(_(EK_LISTE,vals),_(EK_LISTE,list(_(EK_SYMBOLE,"FunctionEnd"),NIL))))return list(NIL);
  if(equal(_(EK_LISTE,vals),_(EK_LISTE,list(_(EK_SYMBOLE,"Undefined_case"),NIL))))return vals;
  if(!null(cdr(vals)) && (equal(car(vals),_(EK_SYMBOLE,"T")) || equal(car(vals),_(EK_SYMBOLE,"T1")) || equal(car(vals),_(EK_SYMBOLE,"T2"))) && est_list(cadr(vals)) && !null(cdadr(vals)) && !equal(_(EK_LISTE,member(_(EK_SYMBOLE,"<->"),*(P_LISTE*)cadr(vals).valeur)),_(EK_LISTE,list(NIL))))
  {
    P_LISTE sthg;
    sthg=Transform_vals(*(P_LISTE*)cadr(vals).valeur,func,arg1,val1,xdraw,ydraw);
    vector_swap((int**)FindValueOf(car(vals),func,arg1,val1,0).valeur,*(int*)FindValueOf(car(sthg),func,arg1,val1,0).valeur-1,*(int*)FindValueOf(caddr(sthg),func,arg1,val1,0).valeur-1);
    return Transform_vals(cons(FindValueOf(car(vals),func,arg1,val1,0),cddr(vals)),func,arg1,val1,xdraw,ydraw);
  }
  if(!null(cdr(vals)) && (equal(car(vals),_(EK_SYMBOLE,"T")) || equal(car(vals),_(EK_SYMBOLE,"T1")) || equal(car(vals),_(EK_SYMBOLE,"T2"))) && est_list(cadr(vals)))
  return Transform_vals(cons(FindValueOf(car(vals),func,arg1,val1,*(int*)FindValueOf(car(Transform_vals(*(P_LISTE*)cadr(vals).valeur,func,arg1,val1,xdraw,ydraw)),func,arg1,val1,0).valeur),cddr(vals)),func,arg1,val1,xdraw,ydraw);
  if(!null(cdr(vals)) && est_symbol(car(vals)) && est_list(cadr(vals)))
  return Transform_vals(cons(Interpret(xdraw,ydraw,car(vals),Transform_vals(*(P_LISTE*)cadr(vals).valeur,func,arg1,val1,xdraw,ydraw),FAUX),cddr(vals)),func,arg1,val1,xdraw,ydraw);
  if(!null(cdr(vals)) && !null(cddr(vals)) && !equal(_(EK_LISTE,member(cadr(vals),list(_(EK_SYMBOLE,"+"),_(EK_SYMBOLE,"-"),_(EK_SYMBOLE,"*"),_(EK_SYMBOLE,"/"),_(EK_SYMBOLE,"%"),NIL))),_(EK_LISTE,list(NIL))) && !est_list(car(vals)) && !est_list(car(cdddr(vals))))
  return Transform_vals(cons(eval(cadr(vals),FindValueOf(car(vals),func,arg1,val1,0),FindValueOf(caddr(vals),func,arg1,val1,0)),cdddr(vals)),func,arg1,val1,xdraw,ydraw);
  if(!null(cdr(vals)) && !null(cddr(vals)) && equal(cadr(vals),_(EK_SYMBOLE,"&")) && equal(caddr(vals),_(EK_SYMBOLE,"vide")))
  return Transform_vals(cons(_(EK_LISTE,cons(FindValueOf(car(vals),func,arg1,val1,0),list(NIL))),cdddr(vals)),func,arg1,val1,xdraw,ydraw);
  if(!null(cdr(vals)) && !null(cddr(vals)) && equal(cadr(vals),_(EK_SYMBOLE,"&")) && (equal(caddr(vals),_(EK_SYMBOLE,"L")) || equal(caddr(vals),_(EK_SYMBOLE,"L1")) || equal(caddr(vals),_(EK_SYMBOLE,"L2"))))
  {  
     if (est_list(car(vals)))
      return Transform_vals(cons(_(EK_LISTE,append(*(P_LISTE*)car(vals).valeur,*(P_LISTE*)FindValueOf(caddr(vals),func,arg1,val1,0).valeur)),cdddr(vals)),func,arg1,val1,xdraw,ydraw);
      return Transform_vals(cons(_(EK_LISTE,cons(FindValueOf(car(vals),func,arg1,val1,0),*(P_LISTE*)FindValueOf(caddr(vals),func,arg1,val1,0).valeur)),cdddr(vals)),func,arg1,val1,xdraw,ydraw);
  }
  if(!null(cdr(vals)) && !null(cddr(vals)) && equal(cadr(vals),_(EK_SYMBOLE,"&")))
  {
    if (est_list(car(vals)))
    return Transform_vals(cons(_(EK_LISTE,append(*(P_LISTE*)car(vals).valeur,list(FindValueOf(caddr(vals),func,arg1,val1,0),NIL))),cdddr(vals)),func,arg1,val1,xdraw,ydraw);
    return Transform_vals(cons(_(EK_LISTE,list(FindValueOf(car(vals),func,arg1,val1,0),FindValueOf(caddr(vals),func,arg1,val1,0),NIL)),cdddr(vals)),func,arg1,val1,xdraw,ydraw);
  }
  if(equal(car(vals),_(EK_SYMBOLE,"vide")))return Transform_vals(cons(_(EK_LISTE,list(NIL)),cdr(vals)),func,arg1,val1,xdraw,ydraw);
  if(est_symbol(car(vals)) && equal(_(EK_LISTE,member(cadr(vals),list(_(EK_SYMBOLE,"+"),_(EK_SYMBOLE,"-"),_(EK_SYMBOLE,"*"),_(EK_SYMBOLE,"/"),_(EK_SYMBOLE,"%"),NIL))),_(EK_LISTE,list(NIL))))
    return cons(FindValueOf(car(vals),func,arg1,val1,0),Transform_vals(cdr(vals),func,arg1,val1,xdraw,ydraw));
  return cons(car(vals),Transform_vals(cdr(vals),func,arg1,val1,xdraw,ydraw));
}

bool evalConds(P_LISTE conds,symbol func,P_LISTE args,P_LISTE vals,P_LISTE accu)
{
  if(null(conds) && (null(accu) || null(cdr(accu)) || null(cddr(accu))))return VRAI;
  if(null(conds))return *(bool*)eval(cadr(accu),FindValueOf(car(accu),func,args,vals,0),FindValueOf(caddr(accu),func,args,vals,0)).valeur;
  if(equal(car(conds),_(EK_SYMBOLE,"tt")))return VRAI;
  if(equal(car(conds),_(EK_SYMBOLE,"ff")))return FAUX;
  if(est_booleen(car(conds)))return *(bool*)car(conds).valeur;
  if(equal(car(conds),_(EK_SYMBOLE,"^")))return *(bool*)eval(cadr(accu),FindValueOf(car(accu),func,args,vals,0),FindValueOf(caddr(accu),func,args,vals,0)).valeur && evalConds(cdr(conds),func,args,vals,list(NIL));
  if(equal(car(conds),_(EK_SYMBOLE,"v")))return *(bool*)eval(cadr(accu),FindValueOf(car(accu),func,args,vals,0),FindValueOf(caddr(accu),func,args,vals,0)).valeur || evalConds(cdr(conds),func,args,vals,list(NIL));
  return evalConds(cdr(conds),func,args,vals,append_val(accu,car(conds)));
}

bool evalConds2(P_LISTE conds,P_LISTE args,P_LISTE vals)
{
  if(null(args) && null(conds))return VRAI;
  if(null(conds) || null(args)){perror("Erreur de prototypage");return FAUX;}
  if(null(vals)){perror("Nombre de parametres insuffisants");return FAUX;}
  if(equal(car(conds),_(EK_SYMBOLE,"vide")))return (null(*(P_LISTE*)car(vals).valeur) && evalConds2(cdr(conds),cdr(args),cdr(vals)));
  if(est_entier(car(conds)))return (*(int*)car(vals).valeur==*(int*)car(conds).valeur && evalConds2(cdr(conds),cdr(args),cdr(vals)));
  if((equal(car(conds),_(EK_SYMBOLE,"c")) || equal(car(conds),_(EK_SYMBOLE,"c1")) || equal(car(conds),_(EK_SYMBOLE,"c2"))) && !null(cdr(conds)) && !null(cddr(conds)) && equal(cadr(conds),_(EK_SYMBOLE,"&")) && equal(caddr(conds),_(EK_SYMBOLE,"vide")))
  return (!null(*(P_LISTE*)car(vals).valeur) && null(cdar(vals)) && evalConds2(cdddr(conds),cdr(args),cdr(vals)));
  return evalConds2(cdr(conds),cdr(args),cdr(vals));
}

P_LISTE buildconds(FILE* fp)
{
  symbol curr;
  curr=read(fp);
  if(equal(curr,_(EK_SYMBOLE,"=>")) || feof(fp))return list(NIL);
  if(equal(curr,_(EK_SYMBOLE,"Initialisation")) || equal(curr,_(EK_SYMBOLE,"Fin")))return list(_(EK_SYMBOLE,"FunctionEnd"),NIL);
  return cons(curr,buildconds(fp));
}

symbol FindValueOf(symbol val,symbol func,P_LISTE args,P_LISTE vals,int ref)
{
  if(null(args))return _(EK_SYMBOLE,"NotFound");
  if(est_entier(val))return val;
  if(!equal(_(EK_LISTE,list(NIL)),_(EK_LISTE,member(val,list(_(EK_SYMBOLE,"+"),_(EK_SYMBOLE,"-"),_(EK_SYMBOLE,"*"),_(EK_SYMBOLE,"/"),_(EK_SYMBOLE,"%"),_(EK_SYMBOLE,"<"),_(EK_SYMBOLE,">"),_(EK_SYMBOLE,"<="),_(EK_SYMBOLE,">="),_(EK_SYMBOLE,"="),_(EK_SYMBOLE,"!="),_(EK_SYMBOLE,"^"),_(EK_SYMBOLE,"v"),_(EK_SYMBOLE,"<->"),_(EK_SYMBOLE,"&"),NIL)))))return val;
  if(est_list(val))return val;
  if(est_tableau(val))return val;
  if(est_booleen(val))return val;
  if(equal(val,func))return func;
  if(equal(val,_(EK_SYMBOLE,"tt")))return _(EK_BOOLEEN,VRAI);
  if(equal(val,_(EK_SYMBOLE,"ff")))return _(EK_BOOLEEN,FAUX);
  if(equal(val,_(EK_SYMBOLE,"vide")))return val;
  if(equal(val,_(EK_SYMBOLE,"L")) && equal(car(args),_(EK_SYMBOLE,"L")))return _(EK_LISTE,cdar(vals));
  if(equal(val,_(EK_SYMBOLE,"L1")) && equal(car(args),_(EK_SYMBOLE,"L1")))return _(EK_LISTE,cdar(vals));
  if(equal(val,_(EK_SYMBOLE,"L2")) && equal(car(args),_(EK_SYMBOLE,"L2")))return _(EK_LISTE,cdar(vals));
  if(equal(val,_(EK_SYMBOLE,"c")) && equal(car(args),_(EK_SYMBOLE,"L"))){if(null(*(P_LISTE*)car(vals).valeur))return _(EK_ENTIER,0);else return caar(vals);}
  if(equal(val,_(EK_SYMBOLE,"c1")) && equal(car(args),_(EK_SYMBOLE,"L1"))){if(null(*(P_LISTE*)car(vals).valeur))return _(EK_ENTIER,0);else return caar(vals);}
  if(equal(val,_(EK_SYMBOLE,"c2")) && equal(car(args),_(EK_SYMBOLE,"L2"))){if(null(*(P_LISTE*)car(vals).valeur))return _(EK_ENTIER,0);else return caar(vals);}
  if(equal(val,car(args)))
  {
    if(ref!=0)
    {
      return _(EK_ENTIER,vector_ref(car(vals),ref-1));
    }
    return car(vals);
  }
  return FindValueOf(val,func,cdr(args),cdr(vals),ref);
}

P_LISTE LoopFunc(P_LISTE conds,P_LISTE conds2,symbol func,P_LISTE args,P_LISTE vals,P_LISTE E1,int* xdraw,int* ydraw)
{
  if(null(conds) || null(conds2) || null(E1))return list(_(EK_SYMBOLE,"Undefined_case"),NIL);
  if(evalConds(Transform_vals(*(P_LISTE*)car(conds).valeur,func,args,vals,xdraw,ydraw),func,args,vals,list(NIL)) && !null(conds2) && evalConds2(*(P_LISTE*)car(conds2).valeur,args,vals))return *(P_LISTE*)car(E1).valeur;
  return LoopFunc(cdr(conds),cdr(conds2),func,args,vals,cdr(E1),xdraw,ydraw);
}
