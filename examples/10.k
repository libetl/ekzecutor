Voici un premier algorithme sur les listes : 
Celui-ci se contente de prendre le k-ieme element d'une liste (k<|L|)

L'exemple suivant montre comment faire appel a une liste : 
Comment prendre son premier element, chercher dans le reste.

Par exemple le quatrieme :

Initialisation Kieme(L,k)=Kieme(c.L,4)
Differents cas k>1 => Kieme(L,k)=Kieme(L,k-1)
               k=1 => Kieme(L,k)=c
Fin

(A noter que la liste perd ses k-1 premiers elements)

Un moyen de ne pas perdre ces elements aurait ete :
Initialisation Kieme(L,k)=Kieme(c.L,4)
Differents cas k>1 => Kieme(L,k)=c.Kieme(L,k-1)
               k=1 => Kieme(L,k)=c.vide
Fin

...et de prendre le dernier element de la liste...