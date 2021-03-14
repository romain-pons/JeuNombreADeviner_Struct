/*************************************************/
// Nom du projet: Jeu du nombre � deviner
// Nom du fichier: Joueur.h
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de cr�ation : 05/02/2021
// R�le du fichier: Contient la d�claration des attributs et m�thodes de la classe qui repr�sente un joueur
// Nom des composants utilises: string
// Historique du fichier:
/*************************************************/
#include <string>
using namespace std;



class CJoueur {

    public:

    // Nom :CJoueur  Constructeur
    // R�le : Initialise toutes les informations du joueur.
    //        Le nombre de tentatives, de parties gagn�es et de parties jou�es seront � 0.
    // Param�tre d'entr�e : un_nom le nom du joueur et son prenom
    // Sortie : le joueur cr��

    CJoueur(string un_prenom, string un_nom);

    // Nom : MajResultats
    // R�le : met � jour les informations d'un joueur
    // Param�tres d'entr�e:
    //                  - le nombre d'essais
    //                  - gagne qui vaut true si le joueur a gagn�, false sinon
    // Entr�e/sortie :
    //                  le joueur dont on met � jour les r�sultats

    void MajResultats(int nbEssais, bool gagne);

    // Nom : Resultats
    // R�le : indique les r�sultats d'un joueur
    //        le nombre de parties gagn�es, le nombre de parties perdues, le nombre d'essais total
    //        La fonction N'affiche PAS les informations � l'�cran
    // Param�tres de sortie:
    //                      - le nombre de succ�s,
    //                      - le nombre d'�checs
    //                      - le nombre total d'essais
    // Entr�e :
    //            -le joueur dont on veut les r�sultats

    void Resultats(int &nbsucces, int &nbechec, int & nbessais);

    // Nom : MoyNbrEssais
    // R�le : indique le nombre d'essais moyen par partie
    // Param�tres de sortie:
    //                      - le nombre moyen d'essais/partie
    // Entr�e :
    //            -le nombre d'essais

    void MoyNbrEssais(float &nbrEssaisMoy);




    // Nom :Nom
    // R�le : retourne le nom d'un joueur
    // Entr�e: le joueur dont on veut le nom
    // Valeur de retour : nom du joueur
    // Entr�e : le joueur dont on veut le nom

    string Nom();

    // Nom :Prenom
    // R�le : retourne le prenom d'un joueur
    // Entr�e: le joueur dont on veut le prenom
    // Valeur de retour : prenom du joueur
    // Entr�e : le joueur dont on veut le prenom

    string Prenom();

    // Nom :CJoueur  destructeur
    // R�le : detruit la classe

    ~CJoueur();

    private :

        string nom;  // nom du joueur
        string prenom;
        int nbPartiesJouees;
        int nbPartiesGagnees;
        int nbTentatives;
};






