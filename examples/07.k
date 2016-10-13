Le programme suivant, bien qu'ayant peu d'utilite, presente quelques artifices :
  - l'inference de type (deduire un type en fonction du nom de variable)
  - les manipulations sur les tableaux
  - l'ecriture compacte courante (ecrire sans trop espacer)

Ici : Parcours de T1 en placant un element a gauche ou a droite par rapport au pivot
(c'est un debut de tri)

Initialisation ECH(T1,i,j,pivot)=ECH(T1,1,|T1|,T[6])
Differents cas i<=j ^ T1[i]>=pivot =>ECH(T1,i,j,pivot)=ECH(T1[i<->j],i,j-1,pivot)
               i<=j ^ T1[i]< pivot =>ECH(T1,i,j,pivot)=ECH(T1,i+1,j,pivot)
               i> j                =>ECH(T1,i,j,pivot)=i

