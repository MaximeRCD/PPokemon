#include <iostream>
using namespace std;
#include "Affichage.h"
#include "Structure.h"
#include "Fonctions.h"

void affiche_menu_jeu() {
	cout << "------------------------ Menu Pokemon ----------------------- \n"
		" 1. Index des pokemons : bestiaire du jeu.\n"
		" 2. Mon Pokedex\n"
		" 3. Attraper un pokemon\n"
		" 4. Power - up et evolution\n"
		" 5. Combat\n"
		" 6. Quitter : Terminer le jeu et fermer l application.\n";
}

void afficheMenu1() {
    cout << endl;
    cout << "1. Attraper ce pokemon" << endl;
    cout << "2. Le laisser partir" << endl;
    cout << "3. Quitter " << endl;
    cout << endl;
}

void afficheMenu2()
{
    cout << endl;
    cout << "1. Faire evoluer mon pokemon" << endl;
    cout << "2. Afficher l'historique des évolutions" << endl;
    cout << "3. Faire augment ses points de combats" << endl;
    cout << "4. Quitter " << endl;
    cout << endl;
}

int choix() {
	cout << "Choisit un menu jeune aventurier \n";
	int choix ;
	cin >> choix;
	return choix;
}

void menu_interactif() {
    //création et initialisation du bestiaire
    especePokemon bestiaire[150];
    init_bestiaire(bestiaire);
    // création du tableau des types
    std::string  typelabel[18] = { "Normal", "Combat", "Flying", "Poison", "Sol", "Roche"," Bug",
                          "Fantome", "Steel", "Feu", "Herbe", "Eau", "Electrique", "Psychique",
                          "Glace", "Dragon", "Dark", "Fairy"};
    Pokedex mon_pokedex;
    initPokedex(&mon_pokedex);
    ressources mes_ressources;
    mes_ressources.bonbons = 0;
    mes_ressources.poussieres = 0;
    pokemon a_attraper;
    Historique* mon_historique;
    mon_historique = initialisation();
    int choice;
    do
    {
        choice = choix();

        switch (choice)
        {
        case 1: // index de pokemon

            char rep;
            cout << " voulez vous afficher le bestiaire trier ? O ou N ";
            cin >> rep;
            if (rep == 'O') { 
                tri(bestiaire);
                affiche_bestaire(bestiaire, typelabel);
            }
            else
            {
                affiche_bestaire(bestiaire,typelabel);
            }
            //affichierindex(bestiaire); // pourquoi ici pas besoin de [] après bestiaire, dans la
            // decla de la fct oui mais l'argument non
            affiche_menu_jeu();
            break;

        case 2:
            affichage_Pokedex(&mon_pokedex,bestiaire,typelabel,&mes_ressources);
            affiche_menu_jeu();
            break;

        case 3: // Attraper un pokemon
            int k;
            do {
                a_attraper = genererPokemon(bestiaire);
                affichage_pokemon(&a_attraper, bestiaire, typelabel);
                afficheMenu1();

                cin >> k;
                if (k == 1)
                {
                    if (random_at_most(100) >= 50) {
                        nouv_ress(&mes_ressources);
                        insertPokemon(&mon_pokedex, &a_attraper);
                    }
                    else {
                        cout << "Le pokemon s'est echapper !! Dommage " << endl;
                        cout << endl;
                    }
                }
            } while (k != 3);
            affiche_menu_jeu();
            break;
            

        case 4:
            afficheMenu2();
            int entier;
            do
            {
                cin >> entier;
                switch (entier)
                {
                case 1:
                    affichage_Pokedex(&mon_pokedex, bestiaire, typelabel, &mes_ressources);
                    cout << " Quel pokemon voullez vous faire evoluer ? " << endl;
                    int l;
                    cin >> l;
                    evolve(&(mon_pokedex.mesPokemons[l]), bestiaire, &mes_ressources, mon_historique);
                    afficheMenu2();
                    break;
                case 2:
                    afficher_historique(mon_historique);
                    afficheMenu2();
                    break;
                case 3:
                    affichage_Pokedex(&mon_pokedex, bestiaire, typelabel, &mes_ressources);
                    cout << " Quel pokemon voullez vous augmenter ?";
                    int k;
                    cin >> k;
                    powerUp(&(mon_pokedex.mesPokemons[k]), &mes_ressources);
                    afficheMenu2();
                    break;
                case 4:
                    affiche_menu_jeu();
                    break;
                default:
                    cout << " Merci de resaisir une valeur " << endl;
                }
            } while (entier != 4);
        case 5:
            break;// Combat
        case 6:
            break;
        default:
            cout << "Je crois que choisir entre 6 valeurs est encore complique pour un inexperimenter\n " << endl;
        }
    } while (choice != 6);
}

void affichage_pokemon(pokemon* p, especePokemon* bestiaire, string* tab ) {
    cout << p->nom << " | ";
    cout << cherchertypepok(bestiaire, p->nom, tab) << " | ";
    cout << p->xp << " xp | " << p->pv << " pv | " << p->cp << " cp | ";
    cout << "et est l'évolution  : " << p->niv << " |  \n";
}

void affiche_bestaire(especePokemon* bestiaire, string* tab) {
    cout << "Les pokemons sauvages que tu peux rencontrer sont \n";
    for (int i = 0; i < 150; i++) {

        cout << bestiaire[i].nom << ", est de type " << cherchertypepok(bestiaire,bestiaire[i].nom,tab) << ", necessite " << bestiaire[i].nb_bonbon_to_evolv << " bonbon pour evoluer en " << bestiaire[i].evolution << endl;
        cout << endl;

    }

}

void affichage_Pokedex(Pokedex* po, especePokemon* bestiaire, string* tab, ressources* m) {
    cout << endl << "Contenu du pokedex -- Actuellement ";
    cout << po->nbPokemon << " pokemons capturés-- " << endl;
    for (int i = 0; i < po->nbPokemon; i++) {
        affichage_pokemon(&(po->mesPokemons[i]), bestiaire, tab);
    }
    cout << "Vous avez actuellement" << m->poussieres << " poussières d'étoiles et " << m->bonbons << " bonbons S! " << endl;
}

void afficher_historique(historique* mon_historique) {
    if (mon_historique == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    evolution* actuel = mon_historique->debut;
    cout << "Ton historique d'évolution de pokemon est le suivant" << endl;
    while (actuel->suivant != NULL)
    {
        cout << "Ton pokemon a evoluer de ";
        cout << actuel->ev_from << " a "; 
        cout << actuel->ev_to << endl;
        actuel = (*actuel).suivant; // actuel -> suivant
    }
}