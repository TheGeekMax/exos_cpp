#include <iostream>
#include "headers/gau.h"
#include "headers/knn.h"
#include "headers/sin.h"
#include "headers/stp.h"
#include "headers/tsdata.h"

int main(){
    TimeSeriesDataset trainData(false, true), testData(false, false);

    GaussianGenerator gsg;
    SinWaveGenerator swg;
    StepGenerator stg;

    vector<double> gaussian1 = gsg.generateTimeSeries(11);
    trainData.addTimeSeries(gaussian1 , 0);
    vector<double> gaussian2 = gsg.generateTimeSeries(11);
    trainData.addTimeSeries(gaussian2 , 0);

    vector<double> sin1 = swg.generateTimeSeries(11);
    trainData.addTimeSeries(sin1, 1);
    vector<double> sin2 = swg.generateTimeSeries(11);
    trainData.addTimeSeries(sin2, 1);

    vector<double> step1 = stg.generateTimeSeries(11);
    trainData.addTimeSeries(step1, 2);
    vector<double> step2 = stg.generateTimeSeries(11);
    trainData.addTimeSeries(step2, 2);

    vector<int> ground_truth;
    testData.addTimeSeries(gsg.generateTimeSeries(11));
    ground_truth.push_back(0);
    testData.addTimeSeries(swg.generateTimeSeries(11));
    ground_truth.push_back(1);
    testData.addTimeSeries(stg.generateTimeSeries(11));
    ground_truth.push_back(2);

    KNN knn_1(1, "dtw");
    cout << "Accuracy: " << knn_1.evaluate(trainData, testData, ground_truth) << endl;

    KNN knn_2(1, "euclidean_distance");
    cout << "Accuracy: " << knn_2.evaluate(trainData, testData, ground_truth) << endl;

    KNN knn_3(2, "euclidean_distance");
    cout << "Accuracy: " << knn_3.evaluate(trainData, testData, ground_truth) << endl;

    return 0;
}
