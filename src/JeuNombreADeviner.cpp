/*************************************************/
// Nom du projet: Jeu du nombre � deviner
// Nom du fichier: JeuNombreADeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de cr�ation : 25/01/2021
// R�le du fichier: Contient le code des fonctions du jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              iostream
//                              ctime
// Historique du fichier: ecriture des fonctions et des commentaires- Romain PONS
/*************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "../include/JeuNombreAdeviner.h"

// Nom :InitJoueur
// R�le : Cr�e un joueur. Initialise toutes les informations du joueur.
//        Le nombre de tentatives, de parties gagn�es et de parties jou�es seront � 0.
// Param�tres d'entr�e : Le nom du joueur
// Param�tres de sortie : Aucun
// Param�tres d'entr�e/sortie : Le joueur cr�er

void InitJoueur(TJoueur& joueurAcreer, string un_nom)
{
    joueurAcreer.nom = un_nom;
    joueurAcreer.nbPartiesJouees = 0;
    joueurAcreer.nbTentatives = 0;
    joueurAcreer.nbPartiesGagnees = 0;
}


// Nom :TirerNombreMystere
// R�le : Tire al�atoirement un nombre � deviner entre 0 et 10
// Valeur de retour : nombre � deviner

int TirerNombreMystere()
{
    int nbrAdeviner = 0;
    srand(time(NULL));
    nbrAdeviner = rand() % 10 + 1;
    return nbrAdeviner;
}


// Nom :JouerPartie
// R�le : Fait jouer une partie au joueur pass� en param�tre
//        A la fin, met � jour les informations du joueur
// Param�tres d'entr�e: Le nombre a deviner
// Param�tres de sortie: Aucun
// Param�tres d'entr�e/sortie : Le joueur

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
            compteur = 4;
        }
    }
    if(nbrSaisi == nombreADeviner){
        etat = true;
        cout << "Vous avez trouve le bon nombre : " << nombreADeviner << " en " << nbrEssais << " essais..." << endl << endl;
        MajResultatsJoueur(un_joueur, nbrEssais, etat);
    }else{
        cout << "C'est perdu le nombre a trouver etait : " << nombreADeviner << endl << endl;
        MajResultatsJoueur(un_joueur, nbrEssais, etat);
    }
}


// Nom : MajResultatsJoueur
// R�le : met � jour les informations du joueur pass� en param�tre
// Param�tres d'entr�e: nombre d'essais, s'il a gagne
// Param�tres de sortie: aucun
// Param�tres d'entr�e/sortie : le joueur

void MajResultatsJoueur(TJoueur &joueur, int nbEssais, bool gagne)
{
   joueur.nbTentatives = joueur.nbTentatives + nbEssais;
   if(gagne){
    joueur.nbPartiesGagnees = joueur.nbPartiesGagnees + 1;
   }
   joueur.nbPartiesJouees = joueur.nbPartiesJouees + 1;
}

// Nom : ResultatsJoueur
// R�le : indique les r�sultats du joueur pass� en param�tre
//        le nombre de parties gagn�es, le nombre de parties perdues, le nombre d'essais total
//        La fonction N'affiche PAS les informations � l'�cran
// Param�tres d'entr�e: nombre de succes, nombre d'echec, nombre d'essais
// Param�tres de sortie: aucun
// Param�tres d'entr�e/sortie : le joueur

void ResultatsJoueur(TJoueur joueur, int& nbsucces, int& nbechec, int& nbessais)
{
    nbessais = joueur.nbTentatives;
    nbechec = joueur.nbPartiesJouees - joueur.nbPartiesGagnees;
    nbsucces = joueur.nbPartiesGagnees;

}

// Nom :Nom
// R�le : retourne le nom du joueur
// Param�tres d'entr�e: le joueur dont on veut le nom
// Valeur de retour : nom du joueur

string Nom(TJoueur joueur){
    return joueur.nom;
}


// Nom : nbrJoueur
// R�le : lance la partie avec le nbr de joueurs indique
// Param�tres d'entr�e : Le nombre de joueurs
// Param�tres de sortie : Aucun
// Param�tres d'entr�e/sortie : Le joueur cr�er

void nbrJoueurPartie (int nbrJoueur){
    int i = 0;
    int nbrPartie = 0;
    TJoueur romain[nbrJoueur];
    while(i < nbrJoueur){
        cout << "Joueur " << i + 1 << " quel est votre nom ?" << endl;
        cin >> romain[i].nom;
        InitJoueur(romain[i], Nom(romain[i]));
        i ++;
    }
    cout << "Combien de parties voulez-vous faire ?" << endl;
    cin >> nbrPartie;
    system("cls");
    i = 0;
    while(i < nbrJoueur){
        Partie(romain[i], nbrPartie);
        i ++;
    }
    i = 0;
    int j = 0;
    TJoueur tmp;
    while(i < nbrJoueur)
    {
        j = i;
        while(j < nbrJoueur)
        {
            if(romain[j].nbPartiesGagnees > romain[i].nbPartiesGagnees){
                tmp = romain[i];
                romain[i] = romain[j];
                romain[j] = tmp;
            }
            if (romain[j].nbPartiesGagnees == romain[i].nbPartiesGagnees){
                if (romain[j].nbTentatives < romain[i].nbTentatives){
                    tmp = romain[i];
                    romain[i] = romain[j];
                    romain[j] = tmp;
                }
            }
            j ++;
        }
        i ++;
    }
    j = 0;
    cout << "Classement : " << endl;
    cout << "-----------------------------------------" << endl;
    while(j < nbrJoueur)
    {
        cout << "Place numero " << j + 1 << " : " << Nom(romain[j]) << " avec " << romain[j].nbPartiesGagnees << " parties gagnees "  << " et "
        << romain[j].nbTentatives << " essais "<< endl;
        j ++;
    }
}


// Nom : Partie
// R�le : joue le nombre de partie indique
// Param�tres d'entr�e : Le nombre de parties, le joueur
// Param�tres de sortie : Aucun
// Param�tres d'entr�e/sortie : Le joueur cr�er

void Partie(TJoueur& un_joueur, int nbrPartie){
    int i = 0;
    while(i < nbrPartie){
        cout << "-------------------------------------------------------" << endl;
        cout << Nom(un_joueur) << ", vous allez jouer pour deviner un nombre secret" << endl;
        int secret = TirerNombreMystere();
        JouerPartie(un_joueur, secret);
        system("cls");
        cout << Nom(un_joueur) << endl;
        cout << "----------------------------------------------" << endl;
        cout << "Nombres de tentavives : " << un_joueur.nbTentatives << endl;
        cout << "Nombres de parties jouees : " << un_joueur.nbPartiesJouees << endl;
        cout << "Nombres de parties gagnees : " << un_joueur.nbPartiesGagnees << endl;
        i ++;
    }
}
