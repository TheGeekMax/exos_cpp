//
// Created by Maxime Sanciaume on 12/11/2024.
//

#include "tsdata.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>

using namespace std;

//// TimeSeriesGenerator class

// constructors

TimeSeriesGenerator::TimeSeriesGenerator():seed(time(NULL)) {
    srand(seed);
}
TimeSeriesGenerator::TimeSeriesGenerator(int seed_):seed(seed_) {
    srand(seed);
}

// methods

void TimeSeriesGenerator::printTimeSeries(vector<double> timeSeries){
    for(int i = 0; i < timeSeries.size(); i++){
        cout << timeSeries[i] << " ";
    }
    cout << endl;
}


//// TimeSeriesDataset class

// constructor

TimeSeriesDataset::TimeSeriesDataset(bool norm, bool trained):znormalize(norm),isTrain(trained),maxLength(0),numberOfSamples(0) {}

// methods

void TimeSeriesDataset::addTimeSeries(vector<double> timeSeries, int label){
    if(znormalize){
        timeSeries = normalize(timeSeries);
    }else{
        data.push_back(timeSeries);
    }
    labels.push_back(label);
    if(timeSeries.size() > maxLength){
        maxLength = timeSeries.size();
    }
    numberOfSamples++;
}

tuple<vector<double>, int> TimeSeriesDataset::getSample(int index){
    vector<double> sample = data[index];
    int label = labels[index];
    return make_tuple(sample, label);
}

vector<double> TimeSeriesDataset::normalize(vector<double> to){
    //step 0, calculate std and avg
    int n = data.size();
    double avg = 0;
    double std = 0;

    for(int j = 0; j < to.size(); j++){
        avg += to[j];
        std += to[j]*to[j];
    }
    avg /= to.size();
    std = sqrt(std/n - avg*avg);

    //step 1, normalize
    for(int i = 0; i < n; i++){
        for(int j = 0; j < data[i].size(); j++){
            data[i][j] = (data[i][j] - avg) / std;
        }
    }
    return to;
}

// static methods

double TimeSeriesDataset::euclideanDistance(vector<double> a, vector<double> b){
    double sum = 0;
    for(int i = 0; i < a.size(); i++){
        sum += (a[i] - b[i])*(a[i] - b[i]);
    }
    return sqrt(sum);
}

double TimeSeriesDataset::dtw(vector<double> a, vector<double> b) {
    // step 0, calculate the distance matrix
    int n = a.size(); // both vectors are same size
    double dist[n+1][n+1];

    // step 1, initialize first line and collumn
    for(int i = 0; i < n+1; i++){
        dist[i][0] = 1000000;
        dist[0][i] = 1000000;
    }

    dist[0][0] = 0;

    //step 2 calculate matrix and distance
    double distance = 0;
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < n+1; j++){
            distance = (a[i-1] - b[j-1])*(a[i-1] - b[j-1]);
            dist[i][j] = distance + min(dist[i-1][j], min(dist[i][j-1], dist[i-1][j-1]));
        }
    }
}
