Astuce : pour choisir les valeurs d'une liste ou d'un tableau, placez la variable dans les premiers arguments et initialisez la comme suit :
(a b c ...) pour une liste
#[a b c ...] pour un tableau

|T| est ici inefficace, un tableau fixe par l'utilisateur doit avoir sa taille determinee par celui-ci.

Voici 11 nombres entre 0 et 10, l'un d'eux manque (il est remplace par 0), determinons lequel :

Initialisation EM(T,i,n,zero) = EM(#[4 10 2 0 3 5 7 6 1 9],1,10,0)
Differents cas i<=n ^ T[i] =0 =>EM(T,i,n,zero)=EM(T,i+1,n,i)
               i<=n ^ T[i]!=i =>EM(T,i,n,zero)=EM(T[i<->T[i]],i,n,zero)
               i<=n ^ T[i] =i =>EM(T,i,n,zero)=EM(T,i+1,n,zero)
               i> n           =>EM(T,i,n,zero)=zero
Fin

(le traitement est choisi par l'utilisateur, la trace sera donc exactement la meme tant que les valeurs du tableau ne seront pas changees par l'utilisateur)