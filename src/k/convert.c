#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "convert.h"

void Convert(FILE* fin,FILE* fout)
{
  char a,b;
  a=fgetc(fin);
  b=fgetc(fin);
  ungetc(b,fin);
  if(a==',')fputc(' ',fout);
  else if(a=='<' && b=='-')
  {fputc(' ',fout);fputc('<',fout);fputc('-',fout);fputc('>',fout);fputc(' ',fout);}
  else if(a=='-' && b=='>')
  fgetc(fin);
  else if(a=='=' && b=='>')
  {fputc(' ',fout);fputc('=',fout);fputc('>',fout);fputc(' ',fout);fgetc(fin);}
  else if(a=='<' && b=='=')
  {fputc(' ',fout);fputc('<',fout);fputc('=',fout);fputc(' ',fout);fgetc(fin);}
  else if(a=='>' && b=='=')
  {fputc(' ',fout);fputc('>',fout);fputc('=',fout);fputc(' ',fout);fgetc(fin);}
  else if(a=='!' && b=='=')
  {fputc(' ',fout);fputc('!',fout);fputc('=',fout);fputc(' ',fout);fgetc(fin);}
  else if(a=='#' && b=='[')
  {fputc(' ',fout);fputc('#',fout);fputc('(',fout);fputc(' ',fout);fgetc(fin);}
  else if(a=='(')
  {fputc(' ',fout);fputc('(',fout);fputc(' ',fout);}
  else if(a==')')
  {fputc(' ',fout);fputc(')',fout);fputc(' ',fout);}
  else if(a=='[')
  {fputc(' ',fout);fputc('(',fout);fputc(' ',fout);}
  else if(a==']')
  {fputc(' ',fout);fputc(')',fout);fputc(' ',fout);}
  else if(a=='=')
  {fputc(' ',fout);fputc('=',fout);fputc(' ',fout);}
  else if(a=='>')
  {fputc(' ',fout);fputc('>',fout);fputc(' ',fout);}
  else if(a=='<')
  {fputc(' ',fout);fputc('<',fout);fputc(' ',fout);}
  else if(a=='+')
  {fputc(' ',fout);fputc('+',fout);fputc(' ',fout);}
  else if(a=='-')
  {fputc(' ',fout);fputc('-',fout);fputc(' ',fout);}
  else if(a=='*')
  {fputc(' ',fout);fputc('*',fout);fputc(' ',fout);}
  else if(a=='/')
  {fputc(' ',fout);fputc('/',fout);fputc(' ',fout);}
  else if(a=='%')
  {fputc(' ',fout);fputc('%',fout);fputc(' ',fout);}
  else if(a=='.')
  {fputc(' ',fout);fputc('&',fout);fputc(' ',fout);}
  else if(a=='\n')
  {fputc(' ',fout);fputc('$',fout);fputc(' ',fout);}
  else fputc(a,fout);
}

void k2kp(char* fstbis)
{
  FILE* fin,*fout;
  fout=fopen("ctmp.kp","w");
  fin=fopen(fstbis,"r+");
  while(!feof(fin))
    Convert(fin,fout);
  fclose(fin);
  fclose(fout);
}

void End(FILE* fp)
{
  fclose(fp);
  remove("ctmp.kp");
}
