Voici un exemple utilisant deux tableaux.
Il consiste a trouver le premier element tel que T1[i]=T2[i]
Il est tout a fait possible de gerer en parallele, deux tableaux, ou deux listes.

Algorithme :
------------

Initialisation COMP(T1,T2,i,n)=COMP(T1,T2,1,|T1|)
Differents cas i<=n ^ T1[i]!=T2[i] => COMP(T1,T2,i,n)=COMP(T1,T2,i+1,n)
               i<=n ^ T1[i] =T2[i] => COMP(T1,T2,i,n)=i
               i>n                 => COMP(T1,T2,i,n)=0
Fin
