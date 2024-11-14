//
// Created by Maxime Sanciaume on 12/11/2024.
//

#ifndef TSDATA_H
#define TSDATA_H
#include <vector>

using namespace std;

class TimeSeriesGenerator {
protected:
    int seed;

public:
    // constructor
    TimeSeriesGenerator();
    TimeSeriesGenerator(int seed_);

    // destructor
    virtual ~TimeSeriesGenerator() = default;

    // usefull methods
    virtual vector<double> generateTimeSeries(int size) = 0;
    void static printTimeSeries(vector<double>);
};

// TimeSeriesDataset

class TimeSeriesDataset {
private:
    vector<vector<double>> data;
    vector<int> labels;
    int maxLength;
    int numberOfSamples;
    bool isTrain;
    bool znormalize;

    vector<double> normalize(vector<double> to);
public:
    TimeSeriesDataset(bool norm, bool trained);
    void addTimeSeries(vector<double> timeSeries, int label);
    tuple<vector<double>, int> getSample(int index);

    //statics methods for distance
    static double euclideanDistance(vector<double> a, vector<double> b);
    static double dtw(vector<double> a, vector<double> b);
};

#endif //TSDATA_H
