/*! 
\file main.c
\author Clément BELLEIL 
\version 1.0
\date 9 décembre 2020
\brief TP_09 main
*/

#include "main.h"
#include "Blackjack.h"

int initJeu(Carte jeu[TAILLE]) {
    int int_i;
    Couleur coul_j;
    int int_k=0;

    
    for (int_i=2;int_i<10;int_i++) { //Cartes de 2 à 9
        for (coul_j=Coeur;coul_j<=Trefle;coul_j++) {
            jeu[int_k].int_valeur=int_i;
            jeu[int_k].int_couleur=coul_j;
            jeu[int_k].bool_distrib=0;
            int_k++;
        }
    }

    for (int_i=1;int_i<5;int_i++) { // Bûches
        for (coul_j=Coeur;coul_j<=Trefle;coul_j++) {
            jeu[int_k].int_valeur=10;
            jeu[int_k].int_couleur=coul_j;
            jeu[int_k].bool_distrib=0;
            int_k++;
        }
    }

    for(coul_j=Coeur;coul_j<=Trefle;coul_j++) { // As
        jeu[int_k].int_valeur=1; // A CHANGER SI ASSOCIE AVEC UNE BUCHE
        jeu[int_k].int_couleur=coul_j;
        jeu[int_k].bool_distrib=0;
        int_k++;
    }

    return 0;
}

void viderBuffer() {
    int c;
    do { 
        c = getchar(); 
        } while (c != '\n' && c!=EOF); 
}

/*!
\fn int main (int argc, char** argv)
\brief lance la partie de blackjack avec le nombre de joueurs passé en argument
\author Clément BELLEIL <belleilcle@eisti.eu>
\version 1.0
\date 17 décembre 2020
\brief TP_09 Blackjack
\param argv valeurs des arg en entrée
\param argc nombre d'arguments en entrée 
\return 0 si tout est ok
*/


int main (int argc,char** argv) {
    int int_nbjoueur;
    char* endPtr;
    if (argc!=2) {
        fprintf(stderr,"Le programme nécessite un et unique argument !\n");
        exit(ERREUR_ARG);
    }
    int_nbjoueur=strtod(argv[1],&endPtr);
    mainBlackjack(int_nbjoueur);
    return 0;
}