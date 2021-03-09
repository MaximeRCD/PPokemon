#pragma once
#include "Structure.h"
#include <cmath>
#include <cstdlib>
#include<stdlib.h>
#include<time.h>

// initialisation du bestiaire
void init_bestiaire(especePokemon bestiaire[]);
// tri du bestiaire
void tri(especePokemon bestiaire[]);
//on cherche le type des pokemons sous la forme d'un string 
std::string cherchertypepok(especePokemon bestiaire[], std::string pokemoncherche, std::string* tab);
// créer un tableau dyn de taille size
pokemon* initTableauDynPokedex(const int size);
// initialise la structure pokedex
void initPokedex(Pokedex* po);
// insert un pokemon dans le tableau dyn
void insertPokemon(Pokedex* po, pokemon* p);
// créer un entier aléatoire
long random_at_most(long max);
// initialisation d'un pokémon sauvage
void init_pokemon(pokemon* p, std::string name, int exp, int pdv, int niv, int cp);
// génération d'un pokemon sauvage
pokemon genererPokemon(especePokemon* bestiaire);
// augmentation des ressources après la capture
void nouv_ress(ressources* p);
// fonction powerUp
void powerUp(pokemon* p, ressources* r);
// fonction evolution 
void evolve(pokemon* p, especePokemon* bestiaire, ressources* r, historique* mon_historique);
// fonction insert evolution pour l'historique
void insert_evolution(historique* mon_historique, std::string from, std::string to);

Historique* initialisation();
// initialisation de la structure hashtable
HashTable* initHT();
// focntion de hashage
int hashfct(std::string str, int max);
//cherhcer le type de pok sous forme de string
//string pokemonTypeToString(PokemonType t);

// get alveole
CombatEspece* getalveole(HashTable* myHashtable, std::string key);
// la table contient il cette clé
bool contains(HashTable* myHashtable, CombatEspece* c);
// insert table de hachage
void insert(CombatEspece* c, HashTable* myHashtable);
//init HT
HashTable* initHashTable(HashTable* hashtable);
// combat
void combat(Pokedex* po, especePokemon* bestiaire, std::string* tab, HashTable* myHashtable);