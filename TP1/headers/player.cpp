//
// Created by Maxime Sanciaume on 04/11/2024.
//

#include "player.h"

#include <iostream>

#include "trainer_card.h"

Player::Player(string playerName) : playerName(playerName) {}


//functions
/**
 *
 * @param card card to add to benchCards
 */
void Player::addCardToBench(Card *card) {
    benchCards.push_back(card);
}

//usables
/**
 *
 * @param indice indice of the pokemon card in benchCards to activate
 */
void Player::activatePokemonCard(int indice) {
    PokemonCard* pokemon = dynamic_cast<PokemonCard*>(benchCards[indice]);
    actionCards.push_back(pokemon);

    //verbose
    cout << "Player " << playerName << " is activating a Pokemon card: " << pokemon->getCardName() << endl;

    //erase from bench
    benchCards.erase(benchCards.begin() + indice);
}

/**
 *
 * @param benchIndice indice of the energy card in benchCards
 * @param actionIndice indice of the pokemon card in actionCards
 */
void Player::attachEnergyCard(int benchIndice, int actionIndice) {
    //get pokemon in actionCards, and apply energy if same type
    PokemonCard* pokemon = actionCards[benchIndice];
    EnergyCard* energy = dynamic_cast<EnergyCard*>(benchCards[actionIndice]);

    //verbose
    cout << "Player " << playerName << " is attaching an energy card of type " << energy->getEnergyType() << " to the Pokemon " << pokemon->getCardName() << endl;

    //erase if energy is attached
    if(pokemon->attachEnergy(energy)) {
        benchCards.erase(benchCards.begin() + actionIndice);
    }
}

/**
 *
 * @param indice indice of the trainer card in benchCards
 */
void Player::useTrainer(int indice) {
    //trainer only heal every pokemon in actionCards
    for(auto &pokemon : actionCards) {
        pokemon->heal();
    }

    TrainerCard* trainer = dynamic_cast<TrainerCard*>(benchCards[indice]);


    //verbose
    cout << playerName << " is using the Trainer Card to " << trainer->getTrainerEffect() << endl;

    //erase trainer
    benchCards.erase(benchCards.begin() + indice);
}

/**
 *
 * @param pokemonIndice indice of the pokemon in actionCards
 * @param attackIndice indice of the attack in the pokemon's attacks
 * @param opponent Player instance to attack
 * @param opponentPokemonIndice Pokemon indice in opponent's actionCards
 */
void Player::attack(int pokemonIndice, int attackIndice, Player &opponent, int opponentPokemonIndice) {
    //get pokemon in actionCards, and apply energy if same type
    PokemonCard* pokemon = actionCards[pokemonIndice];
    PokemonCard* opponentPokemon = opponent.actionCards[opponentPokemonIndice];

    //attack
    bool ko = pokemon->attack(attackIndice, opponentPokemon);

    //verbose
    tuple<int, int, string, int> attack = attackIndice == 0 ? pokemon->getAttack1() : pokemon->getAttack2();
    cout << playerName << " attacking " << opponent.playerName << " pokemon " << opponentPokemon->getCardName() << " with the Pokemon" << pokemon->getCardName() << " attack: " << get<2>(attack) << endl;

    cout << "reducing " << get<3>(attack) << " from " << opponent.playerName << " pokemon " << opponentPokemon->getCardName() << " HP" << endl;
    if(ko) {
        cout << opponent.playerName << " pokemon " << opponentPokemon->getCardName() << " is KO" << endl;
    }
    cout << "Pokemon" << opponentPokemon->getCardName() << " is still alive" << endl;
}

//display
/**
 * display all the bench cards
 */
void Player::displayBench() const {
    cout << "Bench cards for Player " << playerName << ":" << endl;
    for(auto &card : benchCards) {
        card->displayInfo();
    }
}

/**
 * display all the action cards
 */
void Player::displayAction() const {
    cout << "Action cards for Player " << playerName << ":" << endl;
    for(auto &card : actionCards) {
        card->displayInfo();
    }
}

