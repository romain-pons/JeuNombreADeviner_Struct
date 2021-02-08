/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: MainJeuNombreAdeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de création : 25/01/2021
// Rôle du fichier: Contient le code jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              iostream
// Historique du fichier: création du main - Romain PONS
/*************************************************/
#include <iostream>
using namespace std;

#include "../include/JeuNombreADeviner.h"

int main()
{
    int nbrJoueur = 0;
    cout << "Combien de joueur veulent jouer ?" << endl;
    cin >> nbrJoueur;
    nbrJoueurPartie(nbrJoueur);
    return 0;
}

