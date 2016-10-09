N'importe quel commentaire peut etre place avant le debut de l'algorithme.

Il n'y a aucun besoin de le mettre apres ; ou //

On peut creer un espace de pile en demandant de calculer une fois un travail fait.
Par exemple calculer n! revient a demander de multiplier (n-1)! par n.

La factorielle s'ecrit :

Initialisation FAC(n) = FAC(n)
Differents cas n = 0 => FAC(n) = 1
               n > 0 => FAC(n) = n * FAC(n-1)

(La factorielle est le produit des n premiers nombres entre eux 1*2*..*n)
