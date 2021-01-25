/*************************************************/
// Nom du projet: Jeu du nombre � deviner
// Nom du fichier: MainJeuNombreAdeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de cr�ation : 25/01/2021
// R�le du fichier: Contient le code jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              iostream
// Historique du fichier:
/*************************************************/
#include <iostream>
using namespace std;

#include "../include/JeuNombreADeviner.h"

int main()
{
    TJoueur romain;
    InitJoueur(romain, "Romain");
    cout << "Vous allez jouer pour deviner un nombre secret" << endl;
    int secret = TirerNombreMystere();
    JouerPartie(romain, secret);
    return 0;
}

