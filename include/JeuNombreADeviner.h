/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: JeuNombreADeviner.h
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de création : 25/01/2021
// Rôle du fichier: Contient la déclaration du type pour représenter un joueur
// et les fonctions concernant le jeu
// Nom des composants utilises: string
// Historique du fichier:
/*************************************************/
#include <string>
using namespace std;

//Type: structure TJoueur
// Rôle : représente un joueur. Définit les propriétés d'un joueur.

typedef struct {

string nom;  // nom du joueur
int nbPartiesJouees;
int nbPartiesGagnees;
int nbTentatives;
} TJoueur;





// Nom :InitJoueur
// Rôle : Crée un joueur. Initialise toutes les informations du joueur.
//        Le nombre de tentatives, de parties gagnées et de parties jouées seront à 0.
// Paramètres d'entrée : Le nom du joueur
// Paramètres de sortie : Aucun
// Paramètres d'entrée/sortie : Le joueur créer

void InitJoueur (TJoueur &joueurAcreer, string un_nom);


// Nom :TirerNombreMystere
// Rôle : Tire aléatoirement un nombre à deviner entre 0 et 10
// Valeur de retour : nombre à deviner

int TirerNombreMystere();

// Nom :JouerPartie
// Rôle : Fait jouer une partie au joueur passé en paramètre
//        A la fin, met à jour les informations du joueur
// Paramètres d'entrée: Le nombre a deviner
// Paramètres de sortie: Aucun
// Paramètres d'entrée/sortie : Le joueur

void JouerPartie (TJoueur &un_joueur, int nombreADeviner);

// Nom : MajResultatsJoueur
// Rôle : met à jour les informations du joueur passé en paramètre
// Paramètres d'entrée: nombre d'essais, s'il a gagne
// Paramètres de sortie: aucun
// Paramètres d'entrée/sortie : le joueur

void MajResultatsJoueur(TJoueur &joueur, int nbEssais, bool gagne);



// Nom : ResultatsJoueur
// Rôle : indique les résultats du joueur passé en paramètre
//        le nombre de parties gagnées, le nombre de parties perdues, le nombre d'essais total
//        La fonction N'affiche PAS les informations à l'écran
// Paramètres d'entrée: nombre de succes, nombre d'echec, nombre d'essais
// Paramètres de sortie: aucun
// Paramètres d'entrée/sortie : le joueur

void ResultatsJoueur(TJoueur joueur, int &nbsucces, int &nbechec, int & nbessais);


// Nom :Nom
// Rôle : retourne le nom du joueur
// Paramètres d'entrée: le joueur dont on veut le nom
// Valeur de retour : nom du joueur

string Nom(TJoueur joueur);


// Nom : Partie
// Rôle : joue le nombre de partie indique
// Paramètres d'entrée : Le nombre de parties
// Paramètres de sortie : Aucun
// Paramètres d'entrée/sortie : Le joueur créer

void Partie (TJoueur &joueur, int nbrPartie);

// Nom : nbrJoueur
// Rôle : lance la partie avec le nbr de joueurs indique
// Paramètres d'entrée : Le nombre de joueurs
// Paramètres de sortie : Aucun
// Paramètres d'entrée/sortie : Le joueur créer

void nbrJoueurPartie (int nbrJoueur);

