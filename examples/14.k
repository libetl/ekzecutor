Voici un exemple pour synthetiser les connaissances acquises sur les listes en K : 
le tri-fusion.
L'objectif de ce tri est de decomposer d'abord en listes d'un element (listes donc triees) et de fusionner pour obtenir des listes triees de plus en plus grandes, jusqu'a obtenir la liste d'origine triee.

Ce tri est en complexite optimale, il reduit le nombre de comparaisons.

Antecedent: une liste quelconque
Role : Trier par Fusion deux sous-listes
Initialisation TRI(L)=TRI(c.L)
Differents cas        => TRI(vide)=vide
                      => TRI(c.vide)=c.vide
                      => TRI(L)=Fusion(TRI(Impairs(c.L,0)),TRI(Pairs(c.L,0)))
Fin

Antecedent: deux listes triees
Role : construire une liste triee des deux sous-listes
Initialisation Fusion(L1,L2)=Fusion(c1.L1,c2.L2)
Differents cas        => Fusion(vide,L2)=c2.L2
                      => Fusion(L1,vide)=c1.L1
               c1< c2 => Fusion(L1,L2)=c1.Fusion(L1,c2.L2)
               c1>=c2 => Fusion(L1,L2)=c2.Fusion(c1.L1,L2)
Fin

Antecedent: une liste
Role : renvoie la sous-liste des elements d'indices impairs uniquement 
Initialisation Impairs(L,i)=Impairs(c.L,0)
Differents cas        => Impairs(vide,i)=vide
               i%2=0  => Impairs(L,i)=c.Impairs(L,i+1)
               i%2=1  => Impairs(L,i)=Impairs(L,i+1)
Fin

Antecedent: une liste
Role : renvoie la sous-liste des elements d'indices pairs uniquement
Initialisation Pairs(L,i)=Pairs(c.L,0)
Differents cas        => Pairs(vide,i)=vide
               i%2=0  => Pairs(L,i)=Pairs(L,i+1)
               i%2=1  => Pairs(L,i)=c.Pairs(L,i+1)
Fin

A propos : la taille de la console peut depasser en largeur celle de la fenetre, il suffit de faire un deplacement a la souris... On ne peut plus sinon afficher les fonctions intermediaires, celles qui ont le plus d'interet.
