#include <windows.h>
#include <stdio.h>
#include "../scm2C/tads.h"
#include "args.h"
#include "affect.h"
#include "convert.h"
#include "display.h"
#include "interpret.h"
#include "../ek.h"

symbol Interpret(int* xdraw,int* ydraw,symbol Func,P_LISTE Vals,ek_bool DisplayR)
{
  POINT lp[2];
  FILE* fp;
  symbol sym;
  P_LISTE Args,Econds,Econds2,Evals,Accu,conds,loopl,loopl2;
  char str[256]="";
  sym=NIL;
  Args=list(NIL);
  Econds=list(NIL);
  Econds2=list(NIL);
  Evals=list(NIL);
  Accu=list(NIL);
  fp=fopen("ctmp.kp","r+");
  if(DisplayR)*ydraw+=15;
  if(equal(Func,NIL))
  {
    SearchFor(fp,_(EK_SYMBOLE,"Initialisation"));
    Func=read(fp);
  }
  else
  {
    ek_bool found=FAUX;
    while(!found)
    {
      SearchFor(fp,_(EK_SYMBOLE,"Initialisation"));
      if(equal(read(fp),Func))found=VRAI;
    }
  }
  Args=*(P_LISTE*)read(fp).valeur;
  if(null(Vals))
  {
    if(equal(read(fp),_(EK_SYMBOLE,"=")) && equal(read(fp),Func))
      Vals=*(P_LISTE*)read(fp).valeur;
    Vals=ackArgs(Args,Vals,xdraw,ydraw);
    Vals=InitTableValues(Vals,Vals);
    Vals=InitListValues(Vals,Args,Vals);
    Vals=Transform_vals(Vals,Func,Args,Vals,xdraw,ydraw);
    Vals=CheckEmptiness(Vals);
  }

  if(DisplayR)
  {
    TextOut(gc,*xdraw+2,*ydraw+5,*(char**)Func.valeur,strlen(*(char**)Func.valeur));
    *ydraw+=15;
    lp[0].x=*xdraw;lp[1].x=*xdraw+270;
    lp[0].y=*ydraw+2;lp[1].y=*ydraw+2;
    Polyline(gc,lp,2);
    TextOut(gc,*xdraw+2,*ydraw+2,"Valeurs Affectées :",19);
    DisplayVals(xdraw,ydraw,Args,Vals);
  }
  SearchFor(fp,_(EK_SYMBOLE,"cas"));
  while(!feof(fp) && !equal(sym,_(EK_SYMBOLE,"Initialisation")) && !equal(sym,_(EK_SYMBOLE,"Fin")) && !equal(sym,_(EK_LISTE,list(_(EK_SYMBOLE,"FunctionEnd"),NIL))))
  {
    conds=buildconds(fp);
    if(!equal(_(EK_LISTE,Econds),_(EK_LISTE,list(NIL))))
         Econds=append(Econds,list(_(EK_LISTE,conds),NIL));
    else Econds=list(_(EK_LISTE,conds),NIL);
    sym=read(fp);
    if(!feof(fp) && !equal(sym,_(EK_SYMBOLE,"Initialisation")) && !equal(sym,_(EK_SYMBOLE,"Fin")))
    {
      sym=read(fp);
      if(!equal(_(EK_LISTE,Econds2),_(EK_LISTE,list(NIL))))
           Econds2=append(Econds2,list(sym,NIL));
      else Econds2=list(sym,NIL);

    }
    if(!feof(fp) && !equal(sym,_(EK_SYMBOLE,"Initialisation")) && !equal(sym,_(EK_SYMBOLE,"Fin")))
    {
      symbol tmp;
      P_LISTE accf;
      sym=read(fp);
      accf=list(NIL);
      tmp=read(fp);
      while(!feof(fp) && !equal(tmp,_(EK_SYMBOLE,"$")))
      {
        if(!equal(_(EK_LISTE,accf),_(EK_LISTE,list(NIL))))
             accf=append(accf,list(tmp,NIL));
        else accf=list(tmp,NIL);
	tmp=read(fp);
      }
      if(equal(_(EK_LISTE,Evals),_(EK_LISTE,list(NIL))))
         Evals=list(_(EK_LISTE,accf),NIL);
      else Evals=append(Evals,list(_(EK_LISTE,accf),NIL));
    }
  }
  loopl=LoopFunc(Econds,Econds2,Func,Args,Vals,Evals,xdraw,ydraw);
  loopl2=Allwithout(Func,loopl);
  while(!equal(_(EK_LISTE,loopl),_(EK_LISTE,list(_(EK_SYMBOLE,"Undefined_case"),NIL))) && !equal(_(EK_LISTE,list(NIL)),_(EK_LISTE,member(Func,loopl))) && equal(_(EK_LISTE,list(NIL)),_(EK_LISTE,member(Func,cdr(member(Func,loopl))))))
  {
    Accu=append(Accu,stack(Func,Args,Vals,Transform_vals(loopl2,Func,Args,Vals,xdraw,ydraw)));
    Vals=Transform_vals(*(P_LISTE*)cadr(member(Func,loopl)).valeur,Func,Args,Vals,xdraw,ydraw);
    loopl=LoopFunc(Econds,Econds2,Func,Args,Vals,Evals,xdraw,ydraw);
    loopl2=Allwithout(Func,loopl);
  }
  if(equal(car(loopl),_(EK_SYMBOLE,"Undefined_case")))
  {
    TextOut(gc,*xdraw+50,*ydraw+3,"Arrêt : Indécision",18);
    return NIL;
  }
  sym=pops(FindValueOf(car(Transform_vals(Transform_vals(loopl,Func,Args,Vals,xdraw,ydraw),Func,Args,Vals,xdraw,ydraw)),Func,Args,Vals,0),Accu);
  if(!equal(_(EK_LISTE,list(NIL)),_(EK_LISTE,member(_(EK_SYMBOLE,"^"),loopl))) || !equal(_(EK_LISTE,list(NIL)),_(EK_LISTE,member(_(EK_SYMBOLE,"v"),loopl))) || !equal(_(EK_LISTE,list(NIL)),_(EK_LISTE,member(_(EK_SYMBOLE,"ff"),loopl))) || 
     !equal(_(EK_LISTE,list(NIL)),_(EK_LISTE,member(_(EK_SYMBOLE,"tt"),loopl))) || !equal(_(EK_LISTE,list(NIL)),_(EK_LISTE,member(_(EK_SYMBOLE,"<"),loopl))) || !equal(_(EK_LISTE,list(NIL)),_(EK_LISTE,member(_(EK_SYMBOLE,">"),loopl))) || 
     !equal(_(EK_LISTE,list(NIL)),_(EK_LISTE,member(_(EK_SYMBOLE,"<="),loopl))) || !equal(_(EK_LISTE,list(NIL)),_(EK_LISTE,member(_(EK_SYMBOLE,">="),loopl))) || !equal(_(EK_LISTE,list(NIL)),_(EK_LISTE,member(_(EK_SYMBOLE,"="),loopl))))
  sym=_(EK_BOOLEEN,evalConds(Transform_vals(loopl,Func,Args,Vals,xdraw,ydraw),Func,Args,Vals,list(NIL)));
  if(DisplayR)
  {
    TextOut(gc,*xdraw+2,*ydraw+3,*(char**)Func.valeur,strlen(*(char**)Func.valeur));
    *ydraw+=15;
    if(est_entier(sym))
    {
      sprintf(str,"%d",*(int*)sym.valeur);
      TextOut(gc,*xdraw+50,*ydraw+3,str,strlen(str));
    }
    else if(est_tableau(sym))
      DrawTable(*xdraw,*ydraw+3,*(int**)sym.valeur);
    else if(est_list(sym))
      DrawList(*xdraw,*ydraw+3,*(P_LISTE*)sym.valeur);
    else if(est_booleen(sym))
    {
      if(*(ek_bool*)sym.valeur==VRAI)TextOut(gc,*xdraw+50,*ydraw+3,"vrai",4);
      else TextOut(gc,*xdraw+50,*ydraw+3,"faux",4);
    }
    else if(est_symbol(sym))
      TextOut(gc,*xdraw+50,*ydraw+3,*(char**)sym.valeur,strlen(*(char**)sym.valeur));
    TextOut(gc,*xdraw+2,*ydraw+3,"Sortie :",8);
    lp[0].x=*xdraw;lp[1].x=*xdraw+270;
    lp[0].y=*ydraw+2;lp[1].y=*ydraw+2;
    Polyline(gc,lp,2);
    DisplayVals(xdraw,ydraw,Args,Vals);
  }
  End(fp);
  return sym;
}
