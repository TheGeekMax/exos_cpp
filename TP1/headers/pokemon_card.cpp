//
// Created by Maxime Sanciaume on 04/11/2024.
//

#include <iostream>
#include "pokemon_card.h"


//constructor
PokemonCard::PokemonCard(string pokemonName, string pokemonType, string familyName, unsigned int evolutionLevel, unsigned int maxHP, int cout1, string desc1, int dmg1, int cout2, string desc2, int dmg2)
    : familyName(familyName), pokemonType(pokemonType),evolutionLevel(evolutionLevel), MaxHP(maxHP), hp(maxHP) {
    cardName = pokemonName;
    attacks.push_back(make_tuple(cout1,0, desc1, dmg1));
    attacks.push_back(make_tuple(cout2,0, desc2, dmg2));
}

//getters

string PokemonCard::getFamilyName() const {
    return familyName;
}

string PokemonCard::getPokemonType() const {
    return pokemonType;
}

unsigned int PokemonCard::getEvolutionLevel() const {
    return evolutionLevel;
}

unsigned int PokemonCard::getMaxHP() const {
    return MaxHP;
}

int PokemonCard::getHP() const {
    return hp;
}

tuple<int, int, string, int> PokemonCard::getAttack1() const {
    return attacks[0];
}

tuple<int, int, string, int> PokemonCard::getAttack2() const {
    return attacks[1];
}

//functions


void PokemonCard::displayInfo() {
    //main data
    cout << "Pokemon Card - Name: " << cardName;
    cout << ", Type: " << pokemonType;
    cout << ", Evolution Level: " << evolutionLevel;
    cout << ", of the familly: \"" << familyName;
    cout << ", HP :" << hp << "\"" << endl;

    //attacks
    cout << "Attacks: " << endl;

    cout << "Attack #0:" << endl;
    cout << "Attack cost: " << get<0>(attacks[0]) << endl;
    cout << "Attack current energy storage: " << get<1>(attacks[0]) << endl;
    cout << "Attack description: " << get<2>(attacks[0]) << endl;
    cout << "Attack damage: " << get<3>(attacks[0]) << endl;

    cout << "Attack #1:" << endl;
    cout << "Attack cost: " << get<0>(attacks[1]) << endl;
    cout << "Attack current energy storage: " << get<1>(attacks[1]) << endl;
    cout << "Attack description: " << get<2>(attacks[1]) << endl;
    cout << "Attack damage: " << get<3>(attacks[1]) << endl;

}

/**
 *
 * @param energyCard the energy card to attach
 * @return true if the energy card is of the same type as the pokemon, false otherwise
 */
bool PokemonCard::attachEnergy(const EnergyCard *energyCard) {
    //check if the energy card is of the same type as the pokemon
    if (energyCard->getEnergyType() == pokemonType) {
        //add energy to the attacks
        get<1>(attacks[0]) += 1;
        get<1>(attacks[1]) += 1;
        return true;
    }
    return false;
}

/**
 *
 * @param attackNumber 0 for first attack, 1 for second attack
 * @param target Card to attack
 * @return true if the target is KO false otherwise
 */
bool PokemonCard::attack(unsigned int attackNumber, PokemonCard *target) {
    //check if the attack is possible
    if (get<1>(attacks[attackNumber]) >= get<0>(attacks[attackNumber])) {
        //deal damage
        target->damage(get<3>(attacks[attackNumber]));
        //remove energy
        get<1>(attacks[0]) -= get<0>(attacks[attackNumber]);
        get<1>(attacks[1]) -= get<0>(attacks[attackNumber]);

        //check if the target is KO
        if (target->getHP() == 0) {
           return true;
        }
    }
    return false;
}

void PokemonCard::damage(int damage) {
    hp -= damage;
    if (hp < 0) {
        hp = 0;
        cout << "Pokemon " << cardName << " is KO" << endl;
    }
}

void PokemonCard::heal() {
    hp = MaxHP;
}