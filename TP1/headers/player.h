//
// Created by Maxime Sanciaume on 04/11/2024.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>

#include "card.h"
#include "pokemon_card.h"

using namespace std;

class Player {
private:
    string playerName;
    vector<Card*> benchCards;
    vector<PokemonCard*> actionCards;

public:
    Player(string playerName);
    ~Player() = default;

    //functions
    void addCardToBench(Card* card);
    void activatePokemonCard(int indice);
    void attachEnergyCard(int benchIndice, int actionIndice);
    void useTrainer(int indice);
    void attack(int pokemonIndice, int attackIndice, Player &opponent, int opponentPokemonIndice);


    //display
    void displayBench() const;
    void displayAction() const;
};

#endif //PLAYER_H
