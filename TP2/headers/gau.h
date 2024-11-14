//
// Created by Maxime Sanciaume on 12/11/2024.
//

#ifndef GAU_H
#define GAU_H

#include "tsdata.h"

class GaussianGenerator : public TimeSeriesGenerator {
private:
    double avg;
    double std;
public:
    GaussianGenerator();
    GaussianGenerator(int seed, double avg, double std);
    vector<double> generateTimeSeries(int size) override;
    ~GaussianGenerator() override = default;
};



#endif //GAU_H
