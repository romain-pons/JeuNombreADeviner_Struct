/*************************************************/
// Nom du projet: Jeu du nombre � deviner
// Nom du fichier: Partie.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de cr�ation : 05/02/2021
// R�le du fichier: Contient le code des m�thodes d'une partie
// Nom des composants utilises: CJoueur
//                              iostream
//                              ctime
// Historique du fichier:
/*************************************************/

#include <cstdlib>
#include <ctime>

#include <iostream>
using namespace std;
#include "../include/Partie.h"


    // Nom :CPartie (constructeur)
    // R�le : initialise la partie avec le nombre d'essais max, les nombres minimal et maximal � trouver
    // Param�tres d'entr�e:
    //              le nombre d'essais max,
    //              le nombre minimal,
    //              le nombre maximal
    // Sortie : la partie qui est cr��e

     CPartie::CPartie ( int nbmin, int nbmax, int nbessaismax)
    {
        this->nbEssaisMax = nbessaismax;
        this->nbMax = nbmax;
        this->nbMin = nbmin;

    }



    // Nom :JouerPartie
    // R�le : Tire un nombre al�atoire et d�marre la partie
    //        A la fin, met � jour les informations du joueur
    // Parametre d'entr�e/sortie : le joueur
    // Entr�e : la partie qui va se jouer


    void CPartie::Jouer (CJoueur &un_joueur)
    {
         int nombre_propose; // nombre saisi par l'utilisateur

         int nombreADeviner= this->TirerNombreMystere(); // nombre � deviner

        int i; //  nombre de tentatives effectu�es par le joueur

        i = 0;
        bool gagne = false;

        cout << "-------------"<< endl;
        cout << un_joueur.Prenom() << " " << un_joueur.Nom() << " joue" <<endl;
        cout << "-------------"<< endl;

        while (i < 4 && gagne == false)
        {
            i++; // on incr�mente le nombre de tentative
            cout << "Choisir un nombre entre " << this->nbMin << " et " << this->nbMax << endl;

            cin >> nombre_propose;
            if (nombre_propose <  this->nbMin || nombre_propose > this->nbMax)
            {
                cout << "Le nombre doit etre compris entre " << this->nbMin << " et " << this->nbMax<<endl;
                i--;
            }
            else if (nombre_propose == nombreADeviner)
                {
                    gagne = true;
                }
                else if (nombre_propose > nombreADeviner)
                    {
                        cout << "Trop grand !!!" <<endl;

                    }
                    else if (nombre_propose < nombreADeviner)
                        {
                            cout << "Trop petit !!!" << endl;
                        }
        }

        un_joueur.MajResultats(i, gagne);

        if (gagne)
            cout << "Bravo, vous avez gagne !"<<endl;
        else
            cout << "Le nombre d'essais est epuise. La partie est perdue."<< endl;
}


    // Nom :TirerNombreMystere
    // R�le : Tire al�atoirement un nombre � deviner entre 0 et 10
    // Valeur de retour : nombre � deviner
    // Entr�e : la partie pour laquelle est tir�e le nombre myst�re

    int CPartie::TirerNombreMystere()
    {
        srand((int)time(0));
        int nombreADeviner = rand() % (this->nbMax - this->nbMin +1) + this->nbMin;
        return nombreADeviner;
    }



