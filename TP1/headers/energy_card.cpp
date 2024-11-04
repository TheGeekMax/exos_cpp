//
// Created by Maxime Sanciaume on 04/11/2024.
//

#include "energy_card.h"
#include <iostream>

EnergyCard::EnergyCard(string energyType) : energyType(energyType) {
    cardName = "Energy";
}

//getter

string EnergyCard::getEnergyType() const {
    return energyType;
}

//functions

void EnergyCard::displayInfo() {
    cout << "Energy Card of type " << energyType;
}