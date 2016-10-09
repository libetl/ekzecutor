Un tableau est un ensemble d'elements. 
Ils sont appeles par indice, ainsi T[1] est la premiere valeur du tableau.


Ici est detaille un algorithme qui recherche le maximum dans un tableau :

Initialisation MAXIMUM(T, i, n, max) = MAXIMUM(T, 2, |T|, T[1])

T[1] est une valeur par defaut pour demarrer directement a i=2

Differents cas i <= n ^ T[i] >  max => MAXIMUM(T, i, n, max) = MAXIMUM(T, i + 1, n, T[i])
               i <= n ^ T[i] <= max => MAXIMUM(T, i, n, max) = MAXIMUM(T, i + 1, n, max)
               i >  n               => MAXIMUM(T, i, n, max) = max

Fin