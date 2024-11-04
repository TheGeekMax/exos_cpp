//
// Created by Maxime Sanciaume on 04/11/2024.
//

#ifndef TRAINER_CARD_H
#define TRAINER_CARD_H
#include "card.h"
#include <string>

using namespace std;


class TrainerCard : public Card {
private:
    string trainerEffect;
public:
    TrainerCard(string trainerName, string trainerEffect);
    ~TrainerCard() = default;

    //getter
    string getTrainerEffect() const;

    //functions
    void displayInfo() override;
};

#endif //TRAINER_CARD_H
