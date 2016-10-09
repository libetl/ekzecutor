Un exemple de synthese : le tri a bulle.
(Celui-ci n'est pas optimal, car sa complexite est quadratique)

Initialisation TRI(T,i,j,n)=TRI(T,1,1,|T|)
Differents cas i<n ^ j<n ^ T[j]>T[j+1]=>TRI(T,i,j,n)=TRI(T[j<->j+1],i,j+1,n)
               i<n ^ j<n ^ T[j]<=T[j+1]=>TRI(T,i,j,n)=TRI(T,i,j+1,n)
               i<n ^ j>=n =>TRI(T,i,j,n)=TRI(T,i+1,1,n)
               i=n =>TRI(T,i,j,n)=i=n
Fin

Une valeur booleenne est renvoyee. 
'i=n' vrai implique que l'on se soit bien arrete a la fin du tableau, donc que tout le tableau a ete trie.
