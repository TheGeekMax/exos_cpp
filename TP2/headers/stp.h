//
// Created by Maxime Sanciaume on 12/11/2024.
//

#ifndef STP_H
#define STP_H
#include "tsdata.h"


class StepGenerator : public TimeSeriesGenerator {
public:
    vector<double> generateTimeSeries(int size) override;
    ~StepGenerator() override = default;
};



#endif //STP_H
