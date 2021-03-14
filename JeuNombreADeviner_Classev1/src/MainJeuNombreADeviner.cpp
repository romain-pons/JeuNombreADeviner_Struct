/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: MainJeuNombreAdeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de création : 05/02/2021
// Rôle du fichier: Contient le code jeu
// Nom des composants utilises: CPartie
//                              CJoueur
//                              iostream
// Historique du fichier:modification(ajout de tout le TP découverte de la POO) par Romain PONS
/*************************************************/
#include <iostream>
using namespace std;

#include "../include/Partie.h"

int main()
{

    //Création d'un joueur
    cout << "Vous allez jouer pour deviner un nombre secret" << endl;
    cout << "----------------------------------------------"<< endl;
    cout << "Joueur 1 veuillez entrer votre prenom et nom" << endl;
    string un_prenom1;
    cin >> un_prenom1;
    string un_nom1;
    cin >> un_nom1;
    cout << "Joueur 2 veuillez entrer votre prenom et nom" << endl;
    string un_prenom2;
    cin >> un_prenom2;
    string un_nom2;
    cin >> un_nom2;

    // Création du joueur
    CJoueur joueur1 (un_prenom1, un_nom1);
    CJoueur joueur2 (un_prenom2, un_nom2);

    cout << "----------------------------------------------"<< endl;
    cout << "Combien de parties voulez-vous jouer ?" << endl;
    int nbParties;
    cin >> nbParties;


    for (int i = 0; i <nbParties; i++)
    {
        cout << "----------------------------------------------"<< endl;
        cout <<"Partie Numero : " << i+1 << endl;
        cout << "----------------------------------------------"<< endl;

        CPartie partie (0,10,4); // nombre à deviner entre 0 et 10, nombre de tentatives maximum 4

        partie.Jouer(joueur1); // exécution d'une partie pour le joueur1

        partie.Jouer(joueur2); // exécution d'une partie pour le joueur2
    }

    cout << "----------------------------------------------"<< endl;
    cout << "Affichage des resultats du joueur "<< joueur1.Prenom() << " " << joueur1.Nom() << endl;
    cout << "----------------------------------------------"<< endl;

    // Récupération des résultats du joueur
    int nbsucces1, nbechecs1, nbessais1;
    float nbrEssaisMoy1;
    joueur1.Resultats(nbsucces1, nbechecs1, nbessais1);  // les paramètres sont passés par référence
    joueur1.MoyNbrEssais(nbrEssaisMoy1);

    // Affichage des résultats
    cout << "Nombre de parties gagnees : " << nbsucces1 << endl;
    cout << "Nombre de parties perdues : " << nbechecs1 << endl;
    cout << "Nombre de tentatives totales : " << nbessais1 << endl;
    cout << "Nombre de tentatives moyen par partie : " << nbrEssaisMoy1 << endl;

    cout << "----------------------------------------------"<< endl;

    cout << "----------------------------------------------"<< endl;
    cout << "Affichage des resultats du joueur " << joueur2.Prenom() << " " << joueur2.Nom() << endl;
    cout << "----------------------------------------------"<< endl;


    // Récupération des résultats du joueur
    int nbsucces2, nbechecs2, nbessais2;
    float nbrEssaisMoy2;
    joueur2.Resultats(nbsucces2, nbechecs2, nbessais2);  // les paramètres sont passés par référence
    joueur2.MoyNbrEssais(nbrEssaisMoy2);

    // Affichage des résultats
    cout << "Nombre de parties gagnees : " << nbsucces2 << endl;
    cout << "Nombre de parties perdues : " << nbechecs2 << endl;
    cout << "Nombre de tentatives totales : " << nbessais2 << endl;
    cout << "Nombre de tentatives moyen par partie : " << nbrEssaisMoy2 << endl;

    cout << "----------------------------------------------"<< endl;

    cout << "Classement : "<< endl;

    if(nbsucces1 < nbsucces2){
        cout << "Place numero 1 : " << joueur2.Prenom() << " " << joueur2.Nom() << " avec " << nbsucces2 << " parties gagnees et " << nbessais2 << " tentatives" << endl;
        cout << "Place numero 2 : " << joueur1.Prenom() << " " << joueur1.Nom() << " avec " << nbsucces1 << " parties gagnees et " << nbessais1 << " tentatives" << endl;
    }else if(nbsucces1 > nbsucces2){
        cout << "Place numero 1 : " << joueur1.Prenom() << " " << joueur1.Nom() << " avec " << nbsucces1 << " parties gagnees et " << nbessais1 << " tentatives" << endl;
        cout << "Place numero 2 : " << joueur2.Prenom() << " " << joueur2.Nom() << " avec " << nbsucces2 << " parties gagnees et " << nbessais2 << " tentatives" << endl;
    }else{
        if(nbessais1 < nbessais2){
            cout << "Place numero 1 : " << joueur1.Prenom() << " " << joueur1.Nom() << " avec " << nbsucces1 << " parties gagnees et " << nbessais1 << " tentatives" << endl;
            cout << "Place numero 2 : " << joueur2.Prenom() << " " << joueur2.Nom() << " avec " << nbsucces2 << " parties gagnees et " << nbessais2 << " tentatives" << endl;
        }else if(nbessais1 > nbessais2){
            cout << "Place numero 1 : " << joueur2.Prenom() << " " << joueur2.Nom() << " avec " << nbsucces2 << " parties gagnees et " << nbessais2 << " tentatives" << endl;
            cout << "Place numero 2 : " << joueur1.Prenom() << " " << joueur1.Nom() << " avec " << nbsucces1 << " parties gagnees et " << nbessais1 << " tentatives" << endl;
        }else{
            cout << joueur1.Prenom() << " " << joueur1.Nom() << " et " << joueur2.Prenom() << " " << joueur2.Nom() << " sont ex aequo avec " << nbsucces1 << " parties gagnees et " << nbessais1 << " tentatives " << endl;
        }
    }

    return 0;
}

