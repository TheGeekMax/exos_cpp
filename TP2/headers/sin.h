//
// Created by Maxime Sanciaume on 12/11/2024.
//

#ifndef SIN_H
#define SIN_H
#include "tsdata.h"


class SinWaveGenerator : public TimeSeriesGenerator {
private:
    double A;
    double omega;
    double phi;
public:
    SinWaveGenerator();
    SinWaveGenerator(int seed, double A, double omega, double phi);
    vector<double> generateTimeSeries(int size) override;
    ~SinWaveGenerator() override = default;
};



#endif //SIN_H
