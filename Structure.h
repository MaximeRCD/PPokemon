#pragma once
#include <string>
#include "Structure.h"
// le type enuméré décrivant le type de Pokemon parmi les 18 existants
enum PokemonType
{
    Normal, Combat, Flying, Poison, Sol, Roche, Bug,
    Fantome, Steel, Feu, Herbe, Eau, Electrique, Psychique,
    Glace, Dragon, Dark, Fairy
};
//on créer la structure pokemon
typedef struct pokemon{ // typedef permet de ne pas répéter struct pokemeon à chaque fois que l'on en a besoin ailleurs.
	std::string nom; //nom du pokémon
	int xp;   //son nombre d'xp
	int pv;   //son nbr de pv
	int niv;  //son numéro d'évolution
	int cp;   //son nbr de points de combats
}pokemon;
// je créé un nouveau type qui est struct especepokemon dont l'alias est especePokemon
typedef struct especePokemon{
	std::string nom;             // dans le .h on utilise pas using namespace std donc il faut le mettre
	PokemonType type;
	std::string evolution;
	unsigned int nb_bonbon_to_evolv;
	bool estEvolue;
}especePokemon;
//on créer la structure des ressources du joueur
typedef struct ressources {
	int bonbons;
	int poussieres;
}ressources;
// on créer la structure pokedex
typedef struct Pokedex {
	// pointeur vers tableau dynamique de pokemon
	pokemon* mesPokemons;
	int capacite;
	int nbPokemon;
}Pokedex;

typedef struct Evolution {
	std::string ev_from;
	std::string ev_to;
	Evolution* suivant;
}evolution;
typedef struct Historique {
	int nombre;
	Evolution* debut;
}historique;

typedef struct CombatEspece {
	std::string nature;
	std::string strongAgainst[5];
	std::string weakAgainst[5];
	CombatEspece* next;
}combatEspece;

