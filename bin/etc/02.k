Regles syntaxiques:
-------------------
L'operateur != remplace (non (=))
L'operateur %  remplace (modulo)

Les autres operations s'ecrivent dans une notation mathematique simple.
(les parentheses ne sont pas prises en compte) 


Ce qui donne pour le PGCD de deux nombres:

Initialisation PGCD(a, b) =  PGCD(a, b)
Differents cas b  = 0     => PGCD(a, b) = a
               b != 0     => PGCD(a, b) = PGCD(b, a % b)

F(i)=F(i) genere un nombre aleatoire s'il s'agit de la fonction principale