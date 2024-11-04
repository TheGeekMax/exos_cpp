//
// Created by Maxime Sanciaume on 04/11/2024.
//

#ifndef ENERGY_CARD_H
#define ENERGY_CARD_H

#include "card.h"
#include <string>

using namespace std;


class EnergyCard : public Card {
private:
    string energyType;
public:
    EnergyCard(string energyType);
    ~EnergyCard() = default;

    //getter
    string getEnergyType() const;
    void displayInfo() override;
};



#endif //ENERGY_CARD_H
