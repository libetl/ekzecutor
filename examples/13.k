Une liste n'est qu'une suite d'elements...
Il est possible par exemple de demarrer avec une liste vide puis de la creer par plusieurs concatenations de type a.b.[...].L

L'algorithme suivant cree une liste en argument qui a comme valeurs le tableau T retourne.
(i.e Kieme(L,i)=T[|T|-i])

Initialisation Retourner(T,L,i,n)=Retourner(T,vide,1,|T|)
Differents cas i<=n =>Retourner(T,vide,i,n)=Retourner(T,T[i].vide,i+1,n)
               i<=n =>Retourner(T,L,i,n)   =Retourner(T,T[i].c.L,i+1,n)
               i> n =>Retourner(T,L,i,n)   =c.L
Fin
