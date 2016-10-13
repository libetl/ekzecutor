Recursivite :
Il est possible de faire plusieurs appels recursifs a la fois.
Dans ce cas la, la fenetre de resultats montre l'avancee de chacune des fonctions comme s'il s'agissait de fonctions differentes de celle de l'etape en cours.

Voici pour exemple le calcul du deuxieme rang de la suite de Fibonacci :

Initialisation   Fib(a) = Fib(5)
Differents cas =>Fib(0) = 1
               =>Fib(1) = 1
               =>Fib(a) = Fib(a-1) + Fib(a-2)
Fin

Les conditions implicites dans le prototype remplacent des conditions explicites du type a=0, a=1. Par souci de clarete, n'en employez que si l'ecriture de la fonction est simple, comme c'est le cas ici.