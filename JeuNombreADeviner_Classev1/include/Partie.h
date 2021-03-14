/*************************************************/
// Nom du projet: Jeu du nombre � deviner
// Nom du fichier: Partie.h
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de cr�ation : 05/02/2021
// R�le du fichier: Contient la d�claration de attributs et m�thodes de la classe qui repr�sente une partie
// Nom des composants utilises: string, la classe CJoueur
// Historique du fichier:
/*************************************************/
#include <string>
using namespace std;

#include "../include/Joueur.h"
class CPartie {

    public :

    // Nom :CPartie (constructeur)
    // R�le : initialise la partie avec le nombre d'essais max, les nombres minimal et maximal � trouver
    // Param�tres d'entr�e:
    //              le nombre d'essais max,
    //              le nombre minimal,
    //              le nombre maximal
    // Sortie : la partie qui est cr��e

     CPartie ( int nbmin = 0, int nbmax = 10, int nbessaismax = 4);



    // Nom :Jouer
    // R�le : Tire un nombre al�atoire et d�marre la partie
    //        A la fin, met � jour les informations du joueur
    // Parametre d'entr�e/sortie : le joueur
    // Entr�e : la partie qui va se jouer

    void Jouer (CJoueur &joueur);



    private :

        //Nom :TirerNombreMystere
        // R�le : Tire al�atoirement un nombre � deviner entre nbMin et nbMax
        // Valeur de retour : nombre � deviner
        // Entr�e : la partie pour laquelle est tir� le nombre myst�re

        int TirerNombreMystere();



        int nbEssaisMax; // nombre d'essais max

        int nbMin; // nombre minimal � trouver
        int nbMax; // nombre maximal � trouver


};

















