#ifndef AFFECT_H
#define AFFECT_H

int* vector_swap(int** T,int i,int j);
void trier(int* T,int i,int j);
P_LISTE LSort(P_LISTE l);
P_LISTE append_val(P_LISTE liste,symbol elem);
P_LISTE replace_last(P_LISTE accu,symbol elem);
P_LISTE CheckEmptiness(P_LISTE Vals);
P_LISTE Allwithout(symbol sym,P_LISTE L);
P_LISTE stack(symbol func,P_LISTE args,P_LISTE vals,P_LISTE func2);
symbol last(P_LISTE liste);
symbol pops(symbol res,P_LISTE Accu);
void SearchFor(FILE* fp,symbol sym);
#endif
