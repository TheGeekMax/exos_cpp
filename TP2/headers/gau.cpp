//
// Created by Maxime Sanciaume on 12/11/2024.
//

#include "gau.h"

#include <iostream>

using namespace std;

// constructor
GaussianGenerator::GaussianGenerator(): avg(0), std(1) {}
GaussianGenerator::GaussianGenerator(int s, double avg, double std):avg(avg),std(std){
    seed = s;
}


// using Box-Muller method
vector<double> GaussianGenerator::generateTimeSeries(int size) {
    vector<double> ts(size);
    for (int i = 0; i < size; i += 2) {
        double u1 = (double) rand() / RAND_MAX;
        double u2 = (double) rand() / RAND_MAX;
        ts[i] = sqrt(-2 * log(u1)) * cos(2 * M_PI * u2) * std + avg;
        if (i + 1 < size) ts[i + 1] = sqrt(-2 * log(u1)) * sin(2 * M_PI * u2) * std + avg;
    }
    return ts;
}