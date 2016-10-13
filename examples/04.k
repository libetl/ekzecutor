Il est possible de faire appel a une autre fonction comme resultat.

Ceci est neanmoins dangeureux : 
l'entree s'effectue par un appel recursif de la procedure d'interpretation.

A noter : il est recommande d'utiliser le mot cle "Fin" apres chaque fonction. 
(sauf la derniere)
Ceci afin de faciliter la lecture du programme.

Voici un exemple:
-----------------

Initialisation      Essai(i) = Essai(i)
Dans tous les cas =>Essai(i) = Essai2(i-1)

Fin

Initialisation      Essai2(i) = Essai2(i)

     Remarque: les valeurs des arguments n'ont pas d'importance.

Dans tous les cas =>Essai2(i) = i


Attention : c'est la premiere fonction qui est executee, toujours.