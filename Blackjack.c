/*! 
\file Blackjack.c
\author Clément BELLEIL 
\version 1.0
\date 9 décembre 2020
\brief TP_09 Blackjack
*/

#include "Blackjack.h"


int NouvelleManche(int nbjoueur, Joueur liste_j[7]) {
    int int_i;
    int int_choix;
    int int_valretour;

    for(int_i=1;int_i<nbjoueur+1;int_i++) {
        if (liste_j[int_i].int_pot==0) {
            printf("\n%s  Votre pot est à 0 ... la partie s'arrête !\n",liste_j[int_i].char_nom);
            return(PARTIE_TERMINEE);
        }
    }
    printf("\n Voulez vous continuer ?\n");
    printf("1 - Oui on continue !\n");
    printf("2 - Non on arrête !\n");
    int_valretour=scanf("%d",&int_choix);
    while ((int_valretour!=1)||(int_choix>2)||(int_choix==0)) {
        viderBuffer();
        printf("Je ne suis pas sur d'avoir compris, veuillez resaisir votre choix : \n");
        int_valretour=scanf("%d",&int_choix);
    }

    return(int_choix);
}

int verifGagne(int numJoueur,Joueur liste_j[7],Carte Jeu[TAILLE]) {
    int int_i;
    int int_valtot;
    int_valtot=0;
    for (int_i=0;int_i<liste_j[numJoueur].int_nbCartes;int_i++) {
        if ((liste_j[numJoueur].Jeu_joueur[int_i].int_valeur==1)&&(int_valtot+11<=21)) { //As compte pour 11 si cela arrange le joueur ...
            int_valtot=int_valtot+11;
        } else {
            int_valtot=int_valtot+liste_j[numJoueur].Jeu_joueur[int_i].int_valeur; // ... ou pour 1 si le joueur dépasse 21
        }
    }
    if ((int_valtot==21)&&(liste_j[numJoueur].int_nbCartes==2)) { // BUCHE ET AS
        return(-1);
    } else if (int_valtot>=22) {
        return(0);
    } else {
        return (int_valtot);
    }
}

int TourDeJeu(int numJoueur,Joueur liste_j[7],Carte Jeu[TAILLE]) {
    int int_valretour;
    int int_choix;
    if((verifGagne(numJoueur,liste_j,Jeu)==-1)||(verifGagne(numJoueur,liste_j,Jeu)==0)) { //On verifie d'abord qu'il n'a pas fait blackjack avec les 2 cartes
        return(TOUR_FINI);
    }

    printf("\n%s  C'est à votre tour\n",liste_j[numJoueur].char_nom);
    printf("    Souhaitez vous tirer une carte ? ou bien rester ?\n");
    printf("1 - Carte !\n");
    printf("2 - Je reste !\n");
    int_valretour=scanf("%d",&int_choix);
    while ((int_valretour!=1)||(int_choix>2)||(int_choix==0)) {
        viderBuffer();
        printf("Je ne suis pas sur d'avoir compris, veuillez resaisir votre choix : \n");
        int_valretour=scanf("%d",&int_choix);
    }

    while (int_choix==1) {
        demandeCarte(numJoueur,liste_j[numJoueur].int_nbCartes,liste_j,Jeu);
        if(verifGagne(numJoueur,liste_j,Jeu)==0) { //On verifie que le joueur n'a pas bust
            return(TOUR_FINI);
        }
        printf("    Voulez vous retirer une carte, ou non ?\n");
        printf("    1 - Carte !\n");
        printf("    2 - Je reste !\n");
        int_valretour=scanf("%d",&int_choix);
    }
    return(TOUR_FINI);
}



int demandeCarte(int numJoueur,int int_numCarte,Joueur liste_j[7],Carte Jeu[TAILLE]) { //Tire carte et affiche jeu_joueur
    int int_i;
    printf("    Vous avez décider de tirer une carte, votre jeu est maintenant le suivant :\n");
    distribCarte(numJoueur,int_numCarte,liste_j,Jeu);
    for (int_i=0;int_i<int_numCarte+1;int_i++) {
        printf("    Carte %d-> Couleur : %d, Valeur : %d\n",int_i+1,liste_j[numJoueur].Jeu_joueur[int_i].int_couleur,liste_j[numJoueur].Jeu_joueur[int_i].int_valeur);
    }
    liste_j[numJoueur].int_nbCartes=liste_j[numJoueur].int_nbCartes+1;
    return(0);   
}

int distribCarte(int numJoueur,int numCarte,Joueur liste_j[7], Carte Jeu[TAILLE]) {
    int int_rand;
    int_rand=rand()%(TAILLE);
    while ((Jeu[int_rand].bool_distrib)==1) { //Si la carte a déjà été distribué, on en "retire" une.
            int_rand=rand()%(TAILLE);
    }
    Jeu[int_rand].bool_distrib=1; // Carte est distribuée
    liste_j[numJoueur].Jeu_joueur[numCarte]=Jeu[int_rand];
    return(0);     
}

int initJoueur(int nbtour,int numJoueur,Joueur liste_j[7],Carte Jeu[TAILLE]) { //7 joueurs max
    size_t nb1;
    int int_valretour;
    if (nbtour==1) { // Si c'est le premier tour, on "initialise" les profils
        if (numJoueur!=1) {
            viderBuffer();
        }
        if (numJoueur!=0) {
            liste_j[numJoueur].char_nom=NULL;
            printf("Veuillez saisir le nom du joueur %d :\n",numJoueur);
            getline(&liste_j[numJoueur].char_nom, &nb1, stdin);                    

            liste_j[numJoueur].int_pot=200; // POT INITIAL DE CHAQUE JOUEUR (ARBITRAIRE)
            printf("Veuillez saisir votre mise pour ce tour (Pot : %d) : ",liste_j[numJoueur].int_pot); // Mise demandée pour le tour
            int_valretour=scanf("%d",&liste_j[numJoueur].int_mise);
            while ((liste_j[numJoueur].int_mise>liste_j[numJoueur].int_pot)||(int_valretour!=1)||(liste_j[numJoueur].int_mise==0)) {
                viderBuffer();  
                printf("Veuillez resaisir votre mise pour ce tour (Pot : %d) : ",liste_j[numJoueur].int_pot);
                int_valretour=scanf("%d",&liste_j[numJoueur].int_mise);
            } 
        }

        liste_j[numJoueur].int_nbCartes=0; 

        distribCarte(numJoueur,0,liste_j,Jeu);
        distribCarte(numJoueur,1,liste_j,Jeu);

        liste_j[numJoueur].int_nbCartes=2;

        return(0);

    } else { // Si ce n'est pas le premier tour, on a juste besoin de savoir la mise de chacun des joueurs pour le tour
        if (numJoueur!=1) {
        viderBuffer();
        }
        if (numJoueur!=0) {          
            printf("%s  Veuillez saisir votre mise pour ce tour (Pot : %d) : ",liste_j[numJoueur].char_nom,liste_j[numJoueur].int_pot); // Mise demandée pour le tour
            int_valretour=scanf("%d",&liste_j[numJoueur].int_mise);
            while ((liste_j[numJoueur].int_mise>liste_j[numJoueur].int_pot)||(int_valretour!=1)||(liste_j[numJoueur].int_mise==0)) { 
                viderBuffer();
                printf("    Veuillez resaisir votre mise pour ce tour (Pot : %d) : ",liste_j[numJoueur].int_pot);
                int_valretour=scanf("%d",&liste_j[numJoueur].int_mise);
            } 
        }
        liste_j[numJoueur].int_nbCartes=0; 

        distribCarte(numJoueur,0,liste_j,Jeu);
        distribCarte(numJoueur,1,liste_j,Jeu);

        liste_j[numJoueur].int_nbCartes=2;
        return(0);

    }
}



int Blackjack(int nbjoueur,int nbtour) {
    srand(time(NULL));    
    int int_i;
    int int_j;
    Carte Jeu[TAILLE];
    Joueur liste_j[7];

    //INITIALISATION DES JOUEURS ET DE LEUR MAIN, ET DE CELLE DU BANQUIER (J0)
    initJeu(Jeu);
    for(int_i=1;int_i<nbjoueur+1;int_i++) {
        initJoueur(nbtour,int_i,liste_j,Jeu);
    } 
    initJoueur(nbtour,0,liste_j,Jeu);

    //AFFICHAGE JEU INIT
    for (int_i=1;int_i<nbjoueur+1;int_i++) { // Pour chaque joueur, on affiche son jeu initial.
        printf("\n%s  Vos deux cartes initiales sont les suivantes :\n",liste_j[int_i].char_nom);
        for (int_j=0;int_j<2;int_j++) {
            printf("    Carte %d-> Couleur : %d, Valeur : %d\n",int_j+1,liste_j[int_i].Jeu_joueur[int_j].int_couleur,liste_j[int_i].Jeu_joueur[int_j].int_valeur);
        }
    }
    printf("\nLa première carte du banquier est la suivante :\n"); //On montre les cartes du banquier avant de demander aux joueurs de jouer  
    printf("    Carte %d-> Couleur : %d, Valeur : %d\n",1,liste_j[0].Jeu_joueur[0].int_couleur,liste_j[0].Jeu_joueur[0].int_valeur);
    printf("    Sa deuxième est face cachée\n");

    //TOUR DE JEU JOUEURS
    for (int_i=1;int_i<nbjoueur+1;int_i++) {
        TourDeJeu(int_i,liste_j,Jeu);
    }

    //TOUR DE JEU BANQUIER
    printf("\nFinalement, les cartes du banquier sont :\n");
    for (int_i=0;int_i<2;int_i++) {
        printf("    Carte %d-> Couleur : %d, Valeur : %d\n",int_i+1,liste_j[0].Jeu_joueur[int_i].int_couleur,liste_j[0].Jeu_joueur[int_i].int_valeur);
    }  
    while ((verifGagne(0,liste_j,Jeu)<=16)&&(verifGagne(0,liste_j,Jeu)>0)) { //IL TIRE A 16 ET RESTE A 17 TANT QU'IL A PAS DE BLACKJACK
        demandeCarte(0,liste_j[0].int_nbCartes,liste_j,Jeu);
    }

    //RESULTAT
    for (int_i=1;int_i<nbjoueur+1;int_i++) {

        if ((verifGagne(int_i,liste_j,Jeu)==-1)&&(verifGagne(0,liste_j,Jeu)==21)) { //Joueur a fait un blackjack et le banquier a fait 21 en 3 cartes ou plus
            printf("\nBLACKJACK ! le joueur %d remporte le double de sa mise car le banquier a fait 21 !\n",int_i);
            liste_j[int_i].int_pot=liste_j[int_i].int_pot+2*liste_j[int_i].int_mise;
            printf("    Son pot est désormais de : %d\n",liste_j[int_i].int_pot);
            liste_j[int_i].int_mise=0;

        } else if (verifGagne(int_i,liste_j,Jeu)==-1) { //Joueur a fait un blackjack
            printf("\nBLACKJACK ! le joueur %d remporte sa mise !\n",int_i);
            liste_j[int_i].int_pot=liste_j[int_i].int_pot+liste_j[int_i].int_mise;
            printf("    Son pot est désormais de : %d\n",liste_j[int_i].int_pot);
            liste_j[int_i].int_mise=0;

        } else if (verifGagne(0,liste_j,Jeu)==-1 ){ //Banquier a fait un blackjack
            printf("\nBLACKJACK POUR LE BANQUIER! le joueur %d perd sa mise !\n",int_i);
            liste_j[int_i].int_pot=liste_j[int_i].int_pot-liste_j[int_i].int_mise;
            printf("    Son pot est désormais de : %d\n",liste_j[int_i].int_pot);
            liste_j[int_i].int_mise=0;

        } else if (verifGagne(0,liste_j,Jeu)==0) { //Banquier a bust
            printf("\nBUST POUR LE BANQUIER ! le joueur %d remporte sa mise !\n",int_i);
            liste_j[int_i].int_pot=liste_j[int_i].int_pot+liste_j[int_i].int_mise;
            printf("    Son pot est désormais de : %d\n",liste_j[int_i].int_pot);
            liste_j[int_i].int_mise=0;

        } else if (verifGagne(int_i,liste_j,Jeu)==0) { //Joueur a bust
            printf("\nBUST ! le joueur %d perd sa mise car sa valeur totale est supérieure à 21...\n",int_i);
            liste_j[int_i].int_pot=liste_j[int_i].int_pot-liste_j[int_i].int_mise;
            printf("    Son pot est désormais de : %d\n",liste_j[int_i].int_pot);
            liste_j[int_i].int_mise=0;

        }else if ((verifGagne(0,liste_j,Jeu))>(verifGagne(int_i,liste_j,Jeu))) { //Banquier a gagné
            printf("\n%s    Vous perdez votre mise ... la valeur totale du banquier est %d alors que la votre est %d\n",liste_j[int_i].char_nom,verifGagne(0,liste_j,Jeu),verifGagne(int_i,liste_j,Jeu));
            liste_j[int_i].int_pot=liste_j[int_i].int_pot-liste_j[int_i].int_mise;
            printf("        Votre pot est désormais de %d\n",liste_j[int_i].int_pot);
            liste_j[int_i].int_mise=0;
           
        } else if ((verifGagne(0,liste_j,Jeu))<(verifGagne(int_i,liste_j,Jeu))) { //Joueur a gagné
            printf("\n%s    Vous remportez votre mise ! la valeur totale du banquier est %d alors que la votre est %d !\n",liste_j[int_i].char_nom,verifGagne(0,liste_j,Jeu),verifGagne(int_i,liste_j,Jeu));
            liste_j[int_i].int_pot=liste_j[int_i].int_pot+liste_j[int_i].int_mise;
            printf("        Votre pot est désormais de %d !\n",liste_j[int_i].int_pot);
            liste_j[int_i].int_mise=0;
        

        } else { // Egalité
            printf("\nEGALITE, les mises sont conservées. On peut passer au tour suivant !\n\n");
        }
    }

    // TOUR SUIVANT 
    return(NouvelleManche(nbjoueur,liste_j));

}

int mainBlackjack(int int_nbjoueur) {
    int int_nbtour;
    int_nbtour=1;
    printf("###  JEU DE BLACKJACK  ###\n");
    while (Blackjack(int_nbjoueur,int_nbtour)==1) {
        int_nbtour++;
    }
    printf("        Au revoir ! \n");
    return(PARTIE_TERMINEE);
}