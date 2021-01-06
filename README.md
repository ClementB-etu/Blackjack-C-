# Blackjack-C-
Blackjack game, developped for educational purpose

Comments are written in French 

A SAVOIR : 
    - Les couleurs des cartes sont des entiers (cf enum sCarte)
    - Les cartes de même valeur et de même couleur ne sont donc pas distinguables (Valet et Dame de coeur ...)
    - Le banquier est le joueur 0
    - "Bust" signifie avoir un total de points supérieur à 21, et donc une perte de la mise



-Pour compiler le fichier depuis le même répertoire :
	
On utilise le Makefile : 
	make
	
Après avoir compiler le code, on execute le programme compilé, en précisant le nombre de joueur(s) (max. 7) : 
	par exemple : ./TP9 2
	
On peut exectuer "make clean" depuis le même répertoire pour supprimer les fichiers *.o, générés pendant la compilation de notre programme, ainsi que l'executable TP9.

-Pour générer le doxygen, on execute depuis le répertoire contenant le Doxyfile : doxygen Doxyfile.
