//
// Created by Maxime Sanciaume on 12/11/2024.
//

#include "sin.h"

SinWaveGenerator::SinWaveGenerator(): A(1), omega(1), phi(1.618) {}
SinWaveGenerator::SinWaveGenerator(int seed, double A_, double omega_, double phi_): A(A_), omega(omega_), phi(phi_) {
    this->seed = seed;
}

vector<double> SinWaveGenerator::generateTimeSeries(int size) {
    vector<double> ts(size);
    for (int i = 0; i < size; i++) {
        ts[i] = A * sin(omega * i + phi);
    }
    return ts;
}

