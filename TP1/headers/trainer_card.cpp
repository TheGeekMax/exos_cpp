//
// Created by Maxime Sanciaume on 04/11/2024.
//

#include "trainer_card.h"

#include <iostream>
#include <ostream>


TrainerCard::TrainerCard(string trainerName, string trainerEffect) {
    cardName = trainerName;
    this->trainerEffect = trainerEffect;
}

//getter
string TrainerCard::getTrainerEffect() const {
    return trainerEffect;
}

//functions
void TrainerCard::displayInfo() {
    cout << "Trainer Name - " << cardName;
    cout << ", Effect: " << trainerEffect << endl;
}