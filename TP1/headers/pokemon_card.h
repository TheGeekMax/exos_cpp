//
// Created by Maxime Sanciaume on 04/11/2024.
//

#ifndef POKEMONCARD_H
#define POKEMONCARD_H
#include "card.h"
#include <string>
#include <vector>
#include <tuple>

#include "energy_card.h"

using namespace std;


class PokemonCard : public Card {
private:
    string familyName;
    string pokemonType;
    unsigned int evolutionLevel;
    unsigned int MaxHP;
    int hp;
    vector<tuple<int, int, string, int>> attacks;
public:
    PokemonCard(string pokemonName, string pokemonType, string familyName, unsigned int evolutionLevel,
                unsigned int MaxHP,
                int cout1, string desc1, int dmg1,
                int cout2, string desc2, int dmg2);
    ~PokemonCard() = default;

    //getter
    string getFamilyName() const;
    string getPokemonType() const;
    unsigned int getEvolutionLevel() const;
    unsigned int getMaxHP() const;
    int getHP() const;
    tuple<int, int, string, int> getAttack1() const;
    tuple<int, int, string, int> getAttack2() const;

    //functions
    void displayInfo() override;
    bool attachEnergy(const EnergyCard *energyCard);
    bool attack(unsigned int attackNumber, PokemonCard *target);
    void damage(int damage);
    void heal();
};

#endif //POKEMONCARD_H
