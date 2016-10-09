Suppressions de doublons : comparaison algorithme listes/tableaux

Dans un tableau :
Initialisation Doublons(T,i,n)=Doublons(Trié(T),2,|T|)
Differents cas i<=n ^ T[i]=T[i-1] =>Doublons(T,i,n)=Doublons(T[i<->n],i,n-1)
               i<=n               =>Doublons(T,i,n)=Doublons(T,i+1,n)
               i> n               =>Doublons(T,i,n)=n
Fin

'n' est la nouvelle taille du tableau.

Prenez de petits entiers pour mieux comprendre. 
   (menu Execution / Options d'execution)

-----------------------------------------------------------------------------

Dans une liste :
Initialisation Doublons(L,s)=Doublons(Trie(L),100)
Differents cas      =>Doublons(vide,s)=vide
               c=s  =>Doublons(L,s)=Doublons(L,s)
                    =>Doublons(L,s)=c.Doublons(L,c)
Fin

Remarquez la simplicite d'ecriture dans le cas d'une liste.

Les conditions peuvent etre ecrites dans le prototype (c'est a ca qu'il sert).
A l'avenir, preferez F(vide) plutot qu'un test d'indice.