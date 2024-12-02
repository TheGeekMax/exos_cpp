//
// Created by Maxime Sanciaume on 02/12/2024.
//

#ifndef KNN_H
#define KNN_H
#include <string>

class TimeSeriesDataset;
using namespace std;


class KNN {
private:
    int k;
    string similarity_measure;
public:
    //constructor
    KNN();
    KNN(int k, string similarity_measure);

    //desctructor
    ~KNN() = default;


    double evaluate(TimeSeriesDataset train, TimeSeriesDataset test, vector<int> ground_truth);
};



#endif //KNN_H
