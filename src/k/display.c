#include "args.h"
#include "../ek.h"

void DrawTable(int xdraw,int ydraw,int vals[])
{
  int i=0;
  TextOut(gc,xdraw+46,ydraw,"[",1);
  while(vals[i]!=-1)
  {
    char n[256];
    sprintf(n,"%d",vals[i]);
    if(vals[i]>=10)
      TextOut(gc,xdraw+50+20*i,ydraw,n,strlen(n));
    else
    {
      TextOut(gc,xdraw+50+20*i,ydraw,"0",strlen(n));
      TextOut(gc,xdraw+58+20*i,ydraw,n,strlen(n));
    }
    TextOut(gc,xdraw+46+20*(i+1),ydraw,",",1);
    i++;
  }
  TextOut(gc,xdraw+45+i*20,ydraw,"]",1);
}

void DrawList(int xdraw,int ydraw,P_LISTE vals)
{
  int i=0;
  P_LISTE l1;
  l1=vals;
  TextOut(gc,xdraw+42,ydraw,"(",1);
  while(!null(l1))
  {
    char n[256];
    sprintf(n,"%d",*(int*)car(l1).valeur);
    if(*(int*)car(l1).valeur>=10)
    TextOut(gc,xdraw+47+20*i,ydraw,n,strlen(n));
    else
    {
      TextOut(gc,xdraw+47+20*i,ydraw,"0",1);
      TextOut(gc,xdraw+55+20*i,ydraw,n,1);
    }
    TextOut(gc,xdraw+62+20*i,ydraw,",",1);
    i++;
    l1=cdr(l1);
  }
  TextOut(gc,xdraw+42+i*20,ydraw,")",1);
}


void DisplayVals(int *xdraw,int *ydraw,P_LISTE args,P_LISTE vals)
{
  POINT tp[2];
  if(*ydraw>1024-20)
  {
    *ydraw=72;
    *xdraw+=330;
  }
  tp[0].x=*xdraw;tp[1].x=*xdraw+270;
  tp[0].y=*ydraw+17;tp[1].y=*ydraw+17;
  Polyline(gc,tp,2);
  tp[0].x=*xdraw+270;tp[1].x=*xdraw+270;
  tp[0].y=*ydraw+2;tp[1].y=*ydraw+17;
  Polyline(gc,tp,2);
  tp[0].x=*xdraw;tp[1].x=*xdraw;
  tp[0].y=*ydraw+2;tp[1].y=*ydraw+17;
  Polyline(gc,tp,2);
  if(null(args) || null(vals))*ydraw+=30;
  else if(equal(car(args),_(EK_SYMBOLE,"T")) && est_tableau(car(vals)))
  {
    *ydraw+=15;
    TextOut(gc,*xdraw+2,*ydraw+3,"T =",3);
    DrawTable(*xdraw,*ydraw+3,*(int**)car(vals).valeur);
    DisplayVals(xdraw,ydraw,cdr(args),cdr(vals));
  }
  else if(equal(car(args),_(EK_SYMBOLE,"T1")) && est_tableau(car(vals)))
  {
    *ydraw+=15;
    TextOut(gc,*xdraw+2,*ydraw+3,"T1=",3);
    DrawTable(*xdraw,*ydraw+3,*(int**)car(vals).valeur);
    DisplayVals(xdraw,ydraw,cdr(args),cdr(vals));
  }
  else if(equal(car(args),_(EK_SYMBOLE,"T2")) && est_tableau(car(vals)))
  {
    *ydraw+=15;
    TextOut(gc,*xdraw+2,*ydraw+3,"T2=",3);
    DrawTable(*xdraw,*ydraw+3,*(int**)car(vals).valeur);
    DisplayVals(xdraw,ydraw,cdr(args),cdr(vals));
  }
  else if(equal(car(args),_(EK_SYMBOLE,"L")) && est_list(car(vals)))
  {
    *ydraw+=15;
    TextOut(gc,*xdraw+2,*ydraw+3,"L =",3);
    DrawList(*xdraw,*ydraw+3,*(P_LISTE*)car(vals).valeur);
    DisplayVals(xdraw,ydraw,cdr(args),cdr(vals));
  }
  else if(equal(car(args),_(EK_SYMBOLE,"L1")) && est_list(car(vals)))
  {
    *ydraw+=15;
    TextOut(gc,*xdraw+2,*ydraw+3,"L1=",3);
    DrawList(*xdraw,*ydraw+3,*(P_LISTE*)car(vals).valeur);
    DisplayVals(xdraw,ydraw,cdr(args),cdr(vals));
  }
  else if(equal(car(args),_(EK_SYMBOLE,"L2")) && est_list(car(vals)))
  {
    *ydraw+=15;
    TextOut(gc,*xdraw+2,*ydraw+3,"L2=",3);
    DrawList(*xdraw,*ydraw+3,*(P_LISTE*)car(vals).valeur);
    DisplayVals(xdraw,ydraw,cdr(args),cdr(vals));
  }
  else
  {
    char str1[256],str2[256];
    tp[0].x=*xdraw+58;tp[1].x=*xdraw+58;
    tp[0].y=*ydraw+17;tp[1].y=*ydraw+32;
    Polyline(gc,tp,2);
    *ydraw+=15;
    if(est_entier(car(args)))sprintf(str1,"%d",*(int*)car(args).valeur);
    if(est_entier(car(vals)))sprintf(str2,"%d",*(int*)car(vals).valeur);
    if(est_symbol(car(args)))strcpy(str1,*(char**)car(args).valeur);
    if(est_symbol(car(vals)))strcpy(str2,*(char**)car(vals).valeur);
    TextOut(gc,*xdraw+2,*ydraw+3,str1,strlen(str1));
    TextOut(gc,*xdraw+60,*ydraw+3,str2,strlen(str2));
    DisplayVals(xdraw,ydraw,cdr(args),cdr(vals));
  }
}
