/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: JeuNombreADeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de création : 25/01/2021
// Rôle du fichier: Contient le code des fonctions du jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              iostream
//                              ctime
// Historique du fichier:
/*************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "../include/JeuNombreAdeviner.h"

// Nom :InitJoueur
// Rôle : Crée un joueur. Initialise toutes les informations du joueur.
//        Le nombre de tentatives, de parties gagnées et de parties jouées seront à 0.
// Paramètres d'entrée : Le nom du joueur
// Paramètres de sortie : Aucun
// Paramètres d'entrée/sortie : Le joueur créer

void InitJoueur(TJoueur& joueurAcreer, string un_nom)
{
    joueurAcreer.nom = un_nom;
    joueurAcreer.nbPartiesJouees = 0;
    joueurAcreer.nbTentatives = 0;
    joueurAcreer.nbPartiesGagnees = 0;
}


// Nom :TirerNombreMystere
// Rôle : Tire aléatoirement un nombre à deviner entre 0 et 10
// Valeur de retour : nombre à deviner

int TirerNombreMystere()
{
    int nbrAdeviner = 0;
    srand(time(NULL));
    nbrAdeviner = rand() % 10 + 1;
    return nbrAdeviner;
}


// Nom :JouerPartie
// Rôle : Fait jouer une partie au joueur passé en paramètre
//        A la fin, met à jour les informations du joueur
// Paramètres d'entrée: Le nombre a deviner
// Paramètres de sortie: Aucun
// Paramètres d'entrée/sortie : Le joueur

void JouerPartie(TJoueur& un_joueur, int nombreADeviner)
{
    int nbrSaisi, compteur = 1, nbrEssais = 1;
    bool etat = false;
    cout << "Entrez un nombre entre 1 et 10 : ";
    cin >> nbrSaisi;
    while(compteur != 4){
        if(nbrSaisi < nombreADeviner){
            compteur ++;
            cout << "C'est plus !" << endl << endl;
            cout << "Entrez un nouveau nombre : ";
            cin >> nbrSaisi;
            nbrEssais ++;
        }
        else if(nbrSaisi > nombreADeviner){
            compteur ++;
            cout << "C'est moins !" << endl << endl;
            cout << "Entrez un nouveau nombre : ";
            cin >> nbrSaisi;
            nbrEssais ++;
        }
        else{
            etat = true;
            compteur = 4;
        }
    }
    if(nbrSaisi == nombreADeviner){
        cout << "Vous avez trouve le bon nombre : " << nombreADeviner << " en " << nbrEssais << " essais..." << endl << endl;
        MajResultatsJoueur(un_joueur, nbrEssais, etat);
    }else{
        cout << "C'est perdu le nombre a trouver etait : " << nombreADeviner << endl << endl;
        MajResultatsJoueur(un_joueur, nbrEssais, etat);
    }
}


// Nom : MajResultatsJoueur
// Rôle : met à jour les informations du joueur passé en paramètre
// Paramètres d'entrée: nombre d'essais, s'il a gagne
// Paramètres de sortie: aucun
// Paramètres d'entrée/sortie : le joueur

void MajResultatsJoueur(TJoueur &joueur, int nbEssais, bool gagne)
{
   joueur.nbTentatives = joueur.nbTentatives + nbEssais;
   if(gagne){
    joueur.nbPartiesGagnees = joueur.nbPartiesGagnees + 1;
   }
   joueur.nbPartiesJouees = joueur.nbPartiesJouees + 1;
}

// Nom : ResultatsJoueur
// Rôle : indique les résultats du joueur passé en paramètre
//        le nombre de parties gagnées, le nombre de parties perdues, le nombre d'essais total
//        La fonction N'affiche PAS les informations à l'écran
// Paramètres d'entrée: nombre de succes, nombre d'echec, nombre d'essais
// Paramètres de sortie: aucun
// Paramètres d'entrée/sortie : le joueur

void ResultatsJoueur(TJoueur joueur, int& nbsucces, int& nbechec, int& nbessais)
{
    nbessais = joueur.nbTentatives;
    nbechec = joueur.nbPartiesJouees - joueur.nbPartiesGagnees;
    nbsucces = joueur.nbPartiesGagnees;

}

// Nom :Nom
// Rôle : retourne le nom du joueur
// Paramètres d'entrée: le joueur dont on veut le nom
// Valeur de retour : nom du joueur

string Nom(TJoueur joueur){
    return joueur.nom;
}

