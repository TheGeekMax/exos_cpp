//
// Created by Maxime Sanciaume on 12/11/2024.
//

#include "stp.h"

vector<double> StepGenerator::generateTimeSeries(int size) {
    vector<double> ts(size, 0);
    int old = 0;
    for (int i = 0; i < size; i++) {
        if(rand()%2 == 0){
            ts[i] = old;
        } else {
            old = rand()%100;
            ts[i] = old;
        }
    }
    return ts;
}