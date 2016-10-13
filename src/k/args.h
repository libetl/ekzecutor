#include "../scm2C/tads.h"
#ifndef ARGS_H
#define ARGS_H

P_LISTE ackArgs(P_LISTE args,P_LISTE vals,int* xdraw,int* ydraw);
P_LISTE InitTableValues(P_LISTE tab,P_LISTE vals);
P_LISTE InitListValues(P_LISTE lst,P_LISTE args,P_LISTE vals);
P_LISTE Transform_vals(P_LISTE vals,symbol func,P_LISTE arg1,P_LISTE val1,int* xdraw,int* ydraw);
P_LISTE buildconds(FILE* fp);
P_LISTE LoopFunc(P_LISTE conds,P_LISTE conds2,symbol func,P_LISTE args,P_LISTE vals,P_LISTE E1,int* xdraw,int* ydraw);
symbol FindValueOf(symbol val,symbol func,P_LISTE args,P_LISTE vals,int ref);
ek_bool evalConds(P_LISTE conds,symbol func,P_LISTE args,P_LISTE vals,P_LISTE accu);
ek_bool evalConds2(P_LISTE conds,P_LISTE args,P_LISTE vals);
#endif
