/*! 
\file Blackjack.h
\author Clément BELLEIL 
\version 1.0
\date 9 décembre 2020
\brief TP_09 Blackjack
*/

#ifndef __BLACKJACK_H
#define __BLACKJACK_H

#include "main.h"

/*! \struct Joueur
 * Structure pour le stockage des informations des différents joueurs
 */

struct Joueur {
    char* char_nom;         /*!< Nom du joueur */
    int int_pot;            /*!< Pot du joueur, évoluant suivant l'issue des tours qu'il joue */
    int int_mise;           /*!< Mise du joueur pour le tour en cours */
    int int_nbCartes;       /*!< Nombre de carte que le joueur a dans sa main (pour vérifier un blackjack, ou savoir quelle carte tirer le cas échéant) */
    Carte Jeu_joueur[10];   /*!< Tableau de carte correspondant à la main du joueur */
};

typedef struct Joueur Joueur;

/*!
\fn int NouvelleManche(int nbjoueur, Joueur liste_j[7])
\brief demande aux joueurs s'ils veulent continuer la partie, ou termine la partie si un des pots est à 0
\author Clément BELLEIL <belleilcle@eisti.eu>
\version 1.0
\date 17 décembre 2020
\brief TP_09 Blackjack
\param int nbjoueur nombre de joueurs 
\param Joueur liste_j[7] tableau statique contenant les informations des joueurs
\return 1 si les joueurs souhaitent continuer, 2 sinon et 0 si un pot est à 0
*/

int NouvelleManche(int nbjoueur, Joueur liste_j[7]);

/*!
\fn int verifGagne(int numJoueur,Joueur liste_j[7],Carte Jeu[TAILLE])
\brief vérifie que le joueur en argument n'a ni un blackjack, ni bust
\author Clément BELLEIL <belleilcle@eisti.eu>
\version 1.0
\date 17 décembre 2020
\brief TP_09 Blackjack
\param int numJoueur numéro du joueur dont la main est vérifiée
\param Joueur liste_j[7] tableau statique contenant les informations des joueurs
\param Carte jeu[TAILLE] le tableau statique contenant les "TAILLE" cartes, base du jeu de blackjack
\return -1 si le joueur a un blackjack, 0 si il a bust ou la valeur totale de sa main sinon
*/

int verifGagne(int numJoueur,Joueur liste_j[7],Carte Jeu[TAILLE]);

/*!
\fn int TourDeJeu(int numJoueur,Joueur liste_j[7],Carte Jeu[TAILLE])
\brief demande au joueur en argument s'il souhaite retirer une carte ou non
\author Clément BELLEIL <belleilcle@eisti.eu>
\version 1.0
\date 17 décembre 2020
\brief TP_09 Blackjack
\param int numJoueur numéro du joueur dont la main est vérifiée
\param Joueur liste_j[7] tableau statique contenant les informations des joueurs
\param Carte jeu[TAILLE] le tableau statique contenant les "TAILLE" cartes, base du jeu de blackjack
\return TOUR_FINI si tout est ok
*/

int TourDeJeu(int numJoueur,Joueur liste_j[7],Carte Jeu[TAILLE]);

/*!
\fn int initJet(Carte jeu[TAILLE])
\brief initialise le jeu de carte en créant les cartes une à une avec le type Carte
\author Clément BELLEIL <belleilcle@eisti.eu>
\version 1.0
\date 17 décembre 2020
\brief TP_09 Blackjack
\param int numJoueur numéro du joueur dont la main est vérifiée
\param int numCarte numéro de la carte a tiré pour le joueur en argument
\param Joueur liste_j[7] tableau statique contenant les informations des joueurs
\param Carte jeu[TAILLE] le tableau statique contenant les "TAILLE" cartes, base du jeu de blackjack
\return 0 si tout est ok
*/

int demandeCarte(int numJoueur,int numCarte,Joueur liste_j[7],Carte Jeu[TAILLE]);

/*!
\fn int distribCarte(int numJoueur,int numCarte,Joueur liste_j[7], Carte Jeu[TAILLE])
\brief initialise 1 à 1 les 2 cartes constituant la main initial du joueur en argument
\author Clément BELLEIL <belleilcle@eisti.eu>
\version 1.0
\date 17 décembre 2020
\brief TP_09 Blackjack
\param int numJoueur numéro du joueur dont la main est vérifiée
\param int numCarte numéro de la carte a tiré pour le joueur en argument
\param Joueur liste_j[7] tableau statique contenant les informations des joueurs
\param Carte jeu[TAILLE] le tableau statique contenant les "TAILLE" cartes, base du jeu de blackjack
\return 0 si tout est ok
*/

int distribCarte(int numJoueur,int numCarte,Joueur liste_j[7], Carte Jeu[TAILLE]);

/*!
\fn int initJoueur(int nbtour,int numJoueur,Joueur liste_j[7],Carte jeu[TAILLE])
\brief initialise le joueur passé en argument (nom, mise..) si c'est le premier tour, et demande seulement la mise à partir du deuxième tour
\author Clément BELLEIL <belleilcle@eisti.eu>
\version 1.0
\date 17 décembre 2020
\brief TP_09 Blackjack
\param nbtour nombre de tour de jeu
\param int numJoueur numéro du joueur dont la main est vérifiée
\param Joueur liste_j[7] tableau statique contenant les informations des joueurs
\param Carte jeu[TAILLE] le tableau statique contenant les "TAILLE" cartes, base du jeu de blackjack
\return 0 si tout est ok
*/

int initJoueur(int nbtour,int numJoueur,Joueur liste_j[7],Carte jeu[TAILLE]);

/*!
\fn Blackjack(int nbjoueur,int nbtour)
\brief initialise la partie, montre les mains des joueurs ainsi que celle du banquier, et gère les pots des joueurs en fonction de l'issue du tour
\author Clément BELLEIL <belleilcle@eisti.eu>
\version 1.0
\date 17 décembre 2020
\brief TP_09 Blackjack
\param int nbjoueur nombre de joueurs
\param int nbtour numéro du tour qui va commencer
\return 1 si les joueurs souhaitent continuer, 2 sinon et 0 si un pot est à 0
*/

int Blackjack(int nbjoueur,int nbtour);

/*!
\fn int mainBlackjack(int int_nbjoueur)
\brief met à jour nbtour et relance un tour ou non suivant le choix des joueurs
\author Clément BELLEIL <belleilcle@eisti.eu>
\version 1.0
\date 17 décembre 2020
\brief TP_09 Blackjack
\param int nbjoueur nombre de joueurs
\return PARTIE_TERMINEE si tout est ok
*/

int mainBlackjack(int nbjoueur);



#endif
