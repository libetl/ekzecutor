#include <stdio.h>
#include <windows.h>
#include "tads.h"

symbol Symbole(ek_type type,...)
{
  symbol a;
  va_list marker;
  a.type=type;
  va_start(marker,type);
  switch(type)
  {
    case EK_ENTIER:
    {
      int *b;
      b=(int*)malloc(sizeof(int));
      *b=va_arg(marker,int);
      a.valeur=(int*)b;
      break;
    }
    case EK_SYMBOLE:
    {
      char **c;
      c=(char**)malloc(sizeof(char*));
      *c=(char*)malloc(256*sizeof(char));
      strcpy(*c,va_arg(marker,char*));
      a.valeur=(char**)c;
      break;
    }
    case EK_TABLEAU:
    {
      int **b;
      b=(int**)malloc(sizeof(int*));
      *b=malloc(sizeof(int*));
      *b=va_arg(marker,int*);
      a.valeur=(int**)b;
      break;
    }
    case EK_LISTE:
    {
      P_LISTE* b;
      b=malloc(sizeof(P_LISTE));
      *b=malloc(sizeof(T_LISTE));
      *b=va_arg(marker,P_LISTE);
      a.valeur=(P_LISTE*)b;
      break;
    }
    case EK_BOOLEEN:
    {
      ek_bool *b;
      b=malloc(sizeof(ek_bool*));
      *b=va_arg(marker,int);
      a.valeur=(ek_bool*)b;
      break;
    }
  }
  return a;
}

ek_bool est_entier(symbol a)
{
  return a.type==EK_ENTIER;
}

ek_bool est_symbol(symbol a)
{
  return a.type==EK_SYMBOLE;
}

ek_bool est_booleen(symbol a)
{
  return a.type==EK_BOOLEEN;
}

ek_bool est_tableau(symbol a)
{
  return a.type==EK_TABLEAU;
}

ek_bool est_list(symbol a)
{
  return a.type==EK_LISTE;
}

P_LISTE list(symbol arg1,...)
{
  static char tmp[256]="";
  P_LISTE l,l2;
  va_list marker;
  symbol i;
  va_start(marker,arg1);
  i=arg1;
  l2=malloc(sizeof(T_LISTE));
  l=l2;
  if(i.type==EK_SYMBOLE)strcpy(tmp,*(char**)i.valeur);
  else strcpy(tmp,"null");
  while(i.type!=EK_SYMBOLE || tmp[0]!='\0')
  {
    l2->courant=_(i.type,VAL(i));
    l2->suivant=malloc(sizeof(T_LISTE));
    l2=l2->suivant;
    i=va_arg(marker,symbol);
    if(i.type==EK_SYMBOLE)strcpy(tmp,*(char**)i.valeur);
    else strcpy(tmp,"null");
  }
  l2->courant=NIL;
  va_end(marker);
  return l;
}

P_LISTE cons(symbol a,P_LISTE l)
{
  P_LISTE lp;
  lp=malloc(sizeof(T_LISTE));
  lp->courant=a;
  lp->suivant=l;
  return lp;
}

P_LISTE append(P_LISTE l1,P_LISTE l2)
{
  P_LISTE l,lp;
  char tmp[256];
  lp=malloc(sizeof(T_LISTE));
  l=lp;
  if(l1->courant.type==EK_SYMBOLE)strcpy(tmp,*(char**)l1->courant.valeur);
  else strcpy(tmp,"null");
  while(l1->courant.type!=EK_SYMBOLE || tmp[0]!='\0')
  {
    lp->courant=_(l1->courant.type,VAL(l1->courant));
    lp->suivant=malloc(sizeof(T_LISTE));
    lp=lp->suivant;
    l1=l1->suivant;
    if(l1->courant.type==EK_SYMBOLE)strcpy(tmp,*(char**)l1->courant.valeur);
    else strcpy(tmp,"null");
  }
  if(l2->courant.type==EK_SYMBOLE)strcpy(tmp,*(char**)l2->courant.valeur);
  else strcpy(tmp,"null");
  while(l2->courant.type!=EK_SYMBOLE || tmp[0]!='\0')
  {
    lp->courant=_(l2->courant.type,VAL(l2->courant));
    lp->suivant=malloc(sizeof(T_LISTE));
    lp=lp->suivant;
    l2=l2->suivant;
    if(l2->courant.type==EK_SYMBOLE)strcpy(tmp,*(char**)l2->courant.valeur);
    else strcpy(tmp,"null");
  }
  lp->courant=NIL;
  return l;
}

ek_bool null(P_LISTE l)
{
  return l==NULL || l->suivant==NULL || equal(car(l),NIL);
}

symbol car(P_LISTE l)
{
  return l->courant;
}

symbol cadr(P_LISTE l)
{
  return l->suivant->courant;
}

symbol caadr(P_LISTE l)
{
  return caar(cdr(l));
}

symbol caddr(P_LISTE l)
{
  return l->suivant->suivant->courant;
}

symbol cadddr(P_LISTE l)
{
  return l->suivant->suivant->suivant->courant;
}

P_LISTE cdr(P_LISTE l)
{
  return l->suivant;
}

P_LISTE cddr(P_LISTE l)
{
  return cdr(cdr(l));
}

P_LISTE cdddr(P_LISTE l)
{
  return cddr(cdr(l));
}

symbol caar(P_LISTE l)
{
  return car(*(P_LISTE*)car(l).valeur);
}

P_LISTE cdar(P_LISTE l)
{
  return cdr(*(P_LISTE*)car(l).valeur);
}

P_LISTE cdadr(P_LISTE l)
{
  return cdr(*(P_LISTE*)cadr(l).valeur);
}

ek_bool equal(symbol a, symbol b)
{
  if(a.type!=b.type)return FAUX;
  switch(a.type)
  {
    case EK_ENTIER: return VAL(a)==VAL(b);break;
    case EK_SYMBOLE:return strcmp(VAL(a),VAL(b))==0;break;
    case EK_TABLEAU:{
      int i,t,t2;
      t=taille_tableau(a);
      t2=taille_tableau(a);
      if(t!=t2)return FAUX;
      for(i=0;i<t;i++)
        if(*(*(int**)a.valeur+i)!=*(*(int**)b.valeur+i))return FAUX;
	return VRAI;
      break;}
    case EK_LISTE:  if(null(VAL(a)) || null(VAL(b)))return (null(VAL(a)) && null(VAL(b)));
	            return equal(car(VAL(a)),car(VAL(b))) && equal(_(EK_LISTE,cdr(VAL(a))),_(EK_LISTE,cdr(VAL(b))));
		    break;
    case EK_BOOLEEN:return VAL(a)==VAL(b);break;
  }
  return FAUX;
}

int vector_ref(symbol a,int ref)
{
  int* b;
  b=*(int**)a.valeur;
  return b[ref];
}

symbol read(FILE* fp)
{
  symbol a;
  char s[256],c,d;
  do c=fgetc(fp); while(c==' ' || c=='\n' || c=='\r' || c=='\t');
  d=fgetc(fp);

  if(c==')' || c==']')return NIL;

  else if(c=='#' && (d=='(' ||c=='['))
  {
    symbol b=read(fp);
    int *t,n=0;
    t=malloc(sizeof(int));
    while(!(equal(b,NIL)))
    {
      n++;
      t=(int*)realloc(t,n*sizeof(int));
      t[n-1]=*(int*)b.valeur;
      b=read(fp);
    }
    t=(int*)realloc(t,(n+1)*sizeof(int));
    t[n]=-1;
    a=_(EK_TABLEAU,t);
  }

  else if(c=='#')
  {
    if(d=='t')a=_(EK_BOOLEEN,VRAI);
    else a=_(EK_BOOLEEN,FAUX);
  }

  else if(c=='(' || c=='[')
  {
    P_LISTE l,l2;
    symbol b;
    ungetc(d,fp);
    b=read(fp);
    l2=malloc(sizeof(T_LISTE));
    l=l2;
    while(!(equal(b,NIL)))
    {
      l2->courant=b;
      l2->suivant=malloc(sizeof(T_LISTE));
      l2=l2->suivant;
      b=read(fp);
    }
    l2->courant=NIL;
    l2->suivant=malloc(sizeof(T_LISTE));
    a=_(EK_LISTE,l);

  }else{
    ek_bool ent=VRAI;
    int i=0,k;
    a.type=EK_SYMBOLE;
    s[i++]=c;
    ent&=(c>='0' && c<='9');
    while(!feof(fp) && d!=' ' && d!=')')
    {
      ent&=(d>='0' && d<='9');
      s[i++]=d;
      d=fgetc(fp);
    }
    if(d==')')ungetc(d,fp);
    s[i++]='\0';
    if(ent){
      sscanf(s,"%d",&k);
      a=_(EK_ENTIER,k);
    }else a=_(EK_SYMBOLE,s);
  }
  return a;
}

symbol eval(symbol b,symbol a,symbol c)
{
  switch(*(*(char**)b.valeur))
  {
    case '+':return _(EK_ENTIER,*(int*)a.valeur + *(int*)c.valeur);break;
    case '-':return _(EK_ENTIER,*(int*)a.valeur - *(int*)c.valeur);break;
    case '*':return _(EK_ENTIER,*(int*)a.valeur * *(int*)c.valeur);break;
    case '/':return _(EK_ENTIER,*(int*)a.valeur / *(int*)c.valeur);break;
    case '%':return _(EK_ENTIER,*(int*)a.valeur % *(int*)c.valeur);break;
    case '<':
	if(*(*(char**)b.valeur+1)=='=')
          return _(EK_BOOLEEN,*(int*)a.valeur <= *(int*)c.valeur);
	return _(EK_BOOLEEN,*(int*)a.valeur < *(int*)c.valeur);break;
    case '>':
	if(*(*(char**)b.valeur+1)=='=')
          return _(EK_BOOLEEN,*(int*)a.valeur >= *(int*)c.valeur);
	return _(EK_BOOLEEN,*(int*)a.valeur > *(int*)c.valeur);break;
    case '=':return _(EK_BOOLEEN,*(int*)a.valeur == *(int*)c.valeur);break;
    case '!':
	if(*(*(char**)b.valeur+1)=='=')
          return _(EK_BOOLEEN,*(int*)a.valeur != *(int*)c.valeur);break;
  }
  return NIL;
}

P_LISTE member(symbol a,P_LISTE l)
{
 if(null(l))return l;
 if(equal(car(l),a))return l;
 return member(a,cdr(l));
}

int taille_tableau(symbol a)
{
  int* b;
  int s=0;
  b=*(int**)a.valeur;
  while(*b!=-1)
  {
    s++;
    b++;
  }
  return s;
}

char* Aff(symbol a)
{
  switch(a.type)
  {
    case EK_ENTIER:
    {
      char** str;
      str=malloc(sizeof(char*));
      *str=malloc(256*sizeof(char));
      sprintf(*str,"%d",*(int*)a.valeur); 
      return *str;break;
    }
    case EK_SYMBOLE:
      return *(char**)a.valeur;break;
    case EK_BOOLEEN:
      if(*(ek_bool*)a.valeur) return "#t";
      else return "#f";break;
    case EK_LISTE:
      return affliste(*(P_LISTE*)a.valeur);break;
    case EK_TABLEAU:{
      int i=0;
      char** str;
      str=malloc(sizeof(char*));
      *str=malloc(8192*sizeof(char));
      strcpy(*str,"#(");
      while(*(*(int**)a.valeur+i)!=-1)
      {
	char str2[256];
        sprintf(str2,"%d",*(*(int**)a.valeur+i)); 
	strcat(*str,str2);
	if(*(*(int**)a.valeur+i+1)!=-1)
	strcat(*str," ");
	i++;
      }
      strcat(*str,")");
      return *str;
      break;}
    default:break;
  }
  return "(null)";
}

char* affliste(P_LISTE l)
{
  char **a;
  a=malloc(sizeof(char*));
  *a=malloc(8192*sizeof(char));
  strcpy(*a,"(");a[1]='\0';
  if (!(null(l)))
  {
    do{
      strcat(*a,Aff(l->courant));
      l=l->suivant;
      if(l->suivant!=NULL)strcat(*a," ");
    }while(l->suivant!=NULL);
  }
  strcat(*a,")");
  return *a;
}
