Un programme peut utiliser plusieurs structures.
Voici un algorithme performant pour calculer l'intersection de deux ensembles, dans une liste :

Initialisation Inter(T1,T2,i,n,x)=Inter(T1,Trié(T2),1,|T1|,T1[1])
Differents cas i>n                     => Inter(T1,T2,i,n,x)=vide
               i<=n ^ RD(T2,1,11,x)    => Inter(T1,T2,i,n,x)=x.Inter(T1,T2,i+1,n,T1[i+1])
               i<=n                    => Inter(T1,T2,i,n,x)=Inter(T1,T2,i+1,n,T1[i+1])
Fin

^ RD(...) signifie que la fonction a renvoye vrai (tt)
On peut ecrire RD(...)=tt ou dans l'autre cas RD(...)=ff
A noter que l'emploi de 'vide' permet de specifier la liste vide.

RD est la recherche dichotomique dans un tableau trie :
Initialisation RD(T,i,j,a)=RD(Trie(T),1,|T|,a)
Differents cas i<=j ^ T[i+j/2]<a => RD(T,i,j,a)=RD(T,i+j/2+1,j,a)
               i<=j ^ T[i+j/2]>a => RD(T,i,j,a)=RD(T,i,i+j/2-1,a)
               i<=j ^ T[i+j/2]=a => RD(T,i,j,a)=tt
               i> j              => RD(T,i,j,a)=ff
Fin

PS : Il est recommande de :
     - changer la taille de la console
       ou 
     - desactiver l'option 'afficher les resultats intermediaires'.
     (Menu Options / Options d'execution)
