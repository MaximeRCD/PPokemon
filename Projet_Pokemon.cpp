// Projet_Pokemon.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
using namespace std;
#include "Affichage.h"
#include "Fonctions.h"
#include "Structure.h"

int main()
{
    affiche_menu_jeu();
    menu_interactif();
    /*HashTable ht;
    HashTable* hashtable=&ht;
    hashtable->nbr_ele = 0;
    hashtable->nbr_alveole = 18;
    Head* cases[26];
    hashtable->tab = cases;

    // Initialisation
    for (int k = 0; k < 26; k++)
    {
        hashtable->tab[k] = nullptr;
    }
    cout << hashtable->nbr_ele << endl;
    cout << hashtable->nbr_alveole << endl;

    CombatEspece* bug = new CombatEspece;
    bug->nature = "Bug";
    bug->next = nullptr;
    for (int i = 0; i < 5; i++)
    {
        bug->strongAgainst[i] = "none";
        bug->weakAgainst[i] = "none";
    }
    bug->strongAgainst[0] = "Dark";
    bug->strongAgainst[1] = "Herbe";
    bug->strongAgainst[2] = "Psychique";
    bug->weakAgainst[0] = "Feu";
    bug->weakAgainst[1] = "Flying";
    bug->weakAgainst[2] = "Roche";
    insert(bug, hashtable);

    CombatEspece* dark = new CombatEspece;
    dark->nature = "Dark";
    dark->next = nullptr;
    for (int i = 0; i < 5; i++)
    {
        dark->strongAgainst[i] = "none";
        dark->weakAgainst[i] = "none";
    }
    dark->strongAgainst[0] = "Fantome";
    dark->strongAgainst[1] = "Psychique";
    dark->weakAgainst[0] = "Bug";
    dark->weakAgainst[1] = "Fairy";
    dark->weakAgainst[2] = "Fight";
    insert(dark, hashtable);

    CombatEspece* dragon = new CombatEspece;
    dragon->nature = "Dragon";
    dragon->next = nullptr;
    for (int i = 0; i < 5; i++)
    {
        dragon->strongAgainst[i] = "none";
        dragon->weakAgainst[i] = "none";
    }
    dragon->strongAgainst[0] = "Dragon";
    dragon->weakAgainst[0] = "Dragon";
    dragon->weakAgainst[1] = "Fairy";
    dragon->weakAgainst[2] = "Glace";
    insert(dragon, hashtable);

    CombatEspece* Electrique = new CombatEspece;
    Electrique->nature = "Electrique";
    Electrique->next = nullptr;
    for (int i = 0; i < 5; i++)
    {
        Electrique->strongAgainst[i] = "none";
        Electrique->weakAgainst[i] = "none";
    }
    Electrique->strongAgainst[0] = "Flying";
    Electrique->strongAgainst[1] = "Eau";
    Electrique->weakAgainst[0] = "Sol";
    insert(Electrique, hashtable);

    CombatEspece* fairy = new CombatEspece;
    fairy->nature = "Fairy";
    fairy->next = nullptr;
    for (int i = 0; i < 5; i++)
    {
        fairy->strongAgainst[i] = "none";
        fairy->weakAgainst[i] = "none";
    }
    fairy->strongAgainst[0] = "Dark";
    fairy->strongAgainst[1] = "Dragon";
    fairy->strongAgainst[2] = "Fight";
    fairy->weakAgainst[0] = "Poison";
    fairy->weakAgainst[1] = "Steel";
    insert(fairy, hashtable);

    CombatEspece* fighting = new CombatEspece;
    fighting->nature = "Fighting";
    fighting->next = nullptr;
    for (int i = 0; i < 5; i++)
    {
        fighting->strongAgainst[i] = "none";
        fighting->weakAgainst[i] = "none";
    }
    fighting->strongAgainst[0] = "Dark";
    fighting->strongAgainst[1] = "Glace";
    fighting->strongAgainst[2] = "Normal";
    fighting->strongAgainst[3] = "Roche";
    fighting->strongAgainst[4] = "Steel";
    fighting->weakAgainst[0] = "Fairly";
    fighting->weakAgainst[1] = "Flying";
    fighting->weakAgainst[2] = "Psychique";
    insert(fighting, hashtable);

    CombatEspece* Feu = new CombatEspece;
    Feu->nature = "Feu";
    Feu->next = nullptr;
    for (int i = 0; i < 5; i++)
    {
        Feu->strongAgainst[i] = "none";
        Feu->weakAgainst[i] = "none";
    }
    Feu->strongAgainst[0] = "Bug";
    Feu->strongAgainst[1] = "Herbe";
    Feu->strongAgainst[2] = "Glace";
    Feu->strongAgainst[3] = "Steel";
    Feu->weakAgainst[0] = "Sol";
    Feu->weakAgainst[1] = "Roche";
    Feu->weakAgainst[2] = "Eau";
    insert(Feu, hashtable);

    CombatEspece* flying = new CombatEspece;
    flying->nature = "Flying";
    flying->next = nullptr;
    for (int i = 0; i < 5; i++)
    {
        flying->strongAgainst[i] = "none";
        flying->weakAgainst[i] = "none";
    }
    flying->strongAgainst[0] = "Bug";
    flying->strongAgainst[1] = "Fight";
    flying->strongAgainst[2] = "Herbe";
    flying->weakAgainst[0] = "Electrique";
    flying->weakAgainst[1] = "Glace";
    flying->weakAgainst[2] = "Roche";
    insert(flying, hashtable);

    CombatEspece* Fantome = new CombatEspece;
    Fantome->nature = "Fantome";
    Fantome->next = nullptr;
    for (int i = 0; i < 5; i++)
    {
        Fantome->strongAgainst[i] = "none";
        Fantome->weakAgainst[i] = "none";
    }
    Fantome->strongAgainst[0] = "Fantome";
    Fantome->strongAgainst[1] = "Psychique";
    Fantome->weakAgainst[0] = "Dark";
    Fantome->weakAgainst[1] = "Fantome";
    insert(Fantome, hashtable);

    CombatEspece* Herbe = new CombatEspece;
    Herbe->nature = "Herbe";
    Herbe->next = nullptr;
    for (int i = 0; i < 5; i++)
    {
        Herbe->strongAgainst[i] = "none";
        Herbe->weakAgainst[i] = "none";
    }
    Herbe->strongAgainst[0] = "Sol";
    Herbe->strongAgainst[1] = "Roche";
    Herbe->strongAgainst[2] = "Eau";
    Herbe->weakAgainst[0] = "Bug";
    Herbe->weakAgainst[1] = "Feu";
    Herbe->weakAgainst[2] = "Flying";
    Herbe->weakAgainst[3] = "Glace";
    Herbe->weakAgainst[4] = "Poison";
    insert(Herbe, hashtable);

    CombatEspece* Sol = new CombatEspece;
    Sol->nature = "Sol";
    Sol->next = nullptr;
    for (int i = 0; i < 5; i++)
    {
        Sol->strongAgainst[i] = "none";
        Sol->weakAgainst[i] = "none";
    }
    Sol->strongAgainst[0] = "Electrique";
    Sol->strongAgainst[1] = "Feu";
    Sol->strongAgainst[2] = "Poison";
    Sol->strongAgainst[3] = "Roche";
    Sol->strongAgainst[4] = "Steel";
    Sol->weakAgainst[0] = "Herbe";
    Sol->weakAgainst[1] = "Glace";
    Sol->weakAgainst[2] = "Eau";
    insert(Sol, hashtable);

    CombatEspece* Glace = new CombatEspece;
    Glace->nature = "Glace";
    Glace->next = nullptr;
    for (int i = 0; i < 5; i++)
    {
        Glace->strongAgainst[i] = "none";
        Glace->weakAgainst[i] = "none";
    }
    Glace->strongAgainst[0] = "Dragon";
    Glace->strongAgainst[1] = "Flying";
    Glace->strongAgainst[2] = "Herbe";
    Glace->strongAgainst[3] = "Sol";
    Glace->weakAgainst[0] = "Fight";
    Glace->weakAgainst[1] = "Feu";
    Glace->weakAgainst[2] = "Roche";
    Glace->weakAgainst[3] = "Steel";
    insert(Glace, hashtable);

    CombatEspece* normal = new CombatEspece;
    normal->nature = "Normal";
    normal->next = nullptr;
    for (int i = 0; i < 5; i++)
    {
        normal->strongAgainst[i] = "none";
        normal->weakAgainst[i] = "none";
    }
    normal->weakAgainst[0] = "Fight";
    insert(normal, hashtable); // correction ici.

    CombatEspece* poison = new CombatEspece;
    poison->nature = "Poison";
    poison->next = nullptr;
    for (int i = 0; i < 5; i++)
    {
        poison->strongAgainst[i] = "none";
        poison->weakAgainst[i] = "none";
    }
    poison->strongAgainst[0] = "Fairy";
    poison->strongAgainst[1] = "Herbe";
    poison->weakAgainst[0] = "Sol";
    poison->weakAgainst[1] = "Psychique";
    insert(poison, hashtable);

    CombatEspece* Psychique = new CombatEspece;
    Psychique->nature = "Psychique";
    Psychique->next = nullptr;
    for (int i = 0; i < 5; i++)
    {
        Psychique->strongAgainst[i] = "none";
        Psychique->weakAgainst[i] = "none";
    }
    Psychique->strongAgainst[0] = "Fight";
    Psychique->strongAgainst[1] = "Poison";
    Psychique->weakAgainst[0] = "Bug";
    Psychique->weakAgainst[1] = "Dark";
    Psychique->weakAgainst[2] = "Fantome";
    insert(Psychique, hashtable);

    CombatEspece* Roche = new CombatEspece;
    Roche->nature = "Roche";
    Roche->next = nullptr;
    for (int i = 0; i < 5; i++)
    {
        Roche->strongAgainst[i] = "none";
        Roche->weakAgainst[i] = "none";
    }
    Roche->strongAgainst[0] = "Bug";
    Roche->strongAgainst[1] = "Feu";
    Roche->strongAgainst[2] = "Flying";
    Roche->strongAgainst[3] = "Glace";
    Roche->weakAgainst[0] = "Fight";
    Roche->weakAgainst[1] = "Herbe";
    Roche->weakAgainst[2] = "Sol";
    Roche->weakAgainst[3] = "Steel";
    Roche->weakAgainst[4] = "Eau";
    insert(Roche, hashtable);

    CombatEspece* steel = new CombatEspece;
    steel->nature = "Steel";
    steel->next = nullptr;
    for (int i = 0; i < 5; i++)
    {
        steel->strongAgainst[i] = "none";
        steel->weakAgainst[i] = "none";
    }
    steel->strongAgainst[0] = "Fairy";
    steel->strongAgainst[1] = "Glace";
    steel->strongAgainst[2] = "Roche";
    steel->weakAgainst[0] = "Fight";
    steel->weakAgainst[1] = "Feu";
    steel->weakAgainst[2] = "Sol";
    insert(steel, hashtable);

    CombatEspece* Eau = new CombatEspece;
    Eau->nature = "Eau";
    Eau->next = nullptr;
    for (int i = 0; i < 5; i++)
    {
        Eau->strongAgainst[i] = "none";
        Eau->weakAgainst[i] = "none";
    }
    Eau->strongAgainst[0] = "Feu";
    Eau->strongAgainst[1] = "Sol";
    Eau->strongAgainst[2] = "Roche";
    Eau->weakAgainst[0] = "Electrique";
    Eau->weakAgainst[1] = "Herbe";
    insert(Eau, hashtable);

    
    
    cout << hashtable->nbr_ele << endl;
    //vérifier que toute les espèces pokemons sont dans la table
   
   for (int i = 0; i < 26; i++) {
        if (hashtable->tab[i] != nullptr) {
            cout << hashtable->tab[i]->nbr_espece << endl;
        }
    }
    
   cout << getalveole(hashtable, "Fantome")->nature << endl;;
   for (int i = 0; i < 5; i++) {
       cout << getalveole(hashtable, "Fantome")->strongAgainst[i] << endl;
   }
    
   // }*/
    return 0;    
}


// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
