/*! 
\file main.h
\author Clément BELLEIL 
\version 1.0
\date 9 décembre 2020
\brief TP_09 main
*/

#ifndef __MODGESTION_H
#define __MODGESTION_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*!
\def ERREUR_ARG
Code de sortie si l'utilisateur ne saisit pas un argument valide
*/

#define ERREUR_ARG 0

/*!
\def TAILLE
Taille du paquet de carte utilisé
*/

#define TAILLE 52

/*!
\def TOUR_FINI
Code de sortie utilisé lorsqu'un tour entier est terminé.
*/

#define TOUR_FINI 1

/*!
\def PARTIE_TERMINEE
Code de sortie utilisé lorsqu'une partie entière est terminée.
*/

#define PARTIE_TERMINEE 0

/*!\enum eCouleur
 *  Enumeration des couleurs d'un jeu de carte
 * remark Les couleurs seront des entiers dans le cadre de ce TP
 */

enum eCouleur {
    Coeur,      /*!<Couleur Coeur*/
    Carreau,    /*!<Couleur Carreau*/
    Pique,      /*!<Couleur Pique*/
    Trefle      /*!<Couleur Trefle*/
};

typedef enum eCouleur Couleur;

/*! \struct sCarte
 * Structure pour la manipulation des cartes du jeu
 */

struct sCarte {
    int int_valeur;       /*!< Valeur de la carte, en points */
    Couleur int_couleur;  /*!< Couleur de la carte, entier correspondant */  
    int bool_distrib;     /*!< 1 si la carte a été distribuée, 0 sinon  */
};

typedef struct sCarte Carte;

/*!
\fn int initJet(Carte jeu[TAILLE])
\brief initialise le jeu de carte en créant les cartes une à une avec le type Carte
\author Clément BELLEIL <belleilcle@eisti.eu>
\version 1.0
\date 17 décembre 2020
\brief TP_09 Blackjack
\param Carte jeu[TAILLE] le tableau statique contenant les "TAILLE" cartes, base du jeu de blackjack
\return 0 si tout est ok
*/

int initJeu(Carte jeu[TAILLE]);

/*!
\fn void viderBuffer()
\brief vide simplement le buffer clavier
\author Clément BELLEIL <belleilcle@eisti.eu>
\version 1.0
\date 17 décembre 2020
\brief TP_09 Blackjack
*/

void viderBuffer();

#endif
