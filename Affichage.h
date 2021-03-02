#pragma once
#include "Structure.h"


void affiche_menu_jeu();
void afficheMenu1();
void afficheMenu2();
int choix();
void menu_interactif();
void affichage_pokemon(pokemon* p, especePokemon* bestiaire, std::string* tab);
void affiche_bestaire(especePokemon* bestiaire, std::string* tab);
void affichage_Pokedex(Pokedex* po, especePokemon* bestiaire, std::string* tab, ressources* m);
void afficher_historique(historique* mon_historique);