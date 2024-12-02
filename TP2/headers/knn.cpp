//
// Created by Maxime Sanciaume on 02/12/2024.
//

#include "knn.h"

#include <numeric>

#include "tsdata.h"

KNN::KNN(): k(2), similarity_measure("euclidean_distance") {}
KNN::KNN(int k, string similarity_measure): k(k), similarity_measure(similarity_measure) {}


double KNN::evaluate(TimeSeriesDataset train, TimeSeriesDataset test, vector<int> ground_truth) {
    if(similarity_measure == "euclidean_distance") {
        // Euclidean distance
        vector<int> predictions;
        for(int i = 0; i < test.get_size(); i++) {
            vector<double> distances;
            for(int j = 0; j < train.get_size(); j++) {
                double distance = 0;
                for(int k = 0; k < test.get_dim(); k++) {
                    distance += pow(test.get_ts(i)[k] - train.get_ts(j)[k], 2);
                }
                distances.push_back(sqrt(distance));
            }
            vector<int> indices(distances.size());
            iota(indices.begin(), indices.end(), 0);
            sort(indices.begin(), indices.end(), [&distances](int i1, int i2) {return distances[i1] < distances[i2];});
            int count = 0;
            for(int j = 0; j < k; j++) {
                count += ground_truth[indices[j]];
            }
            predictions.push_back(count > k/2);
        }
        double accuracy = 0;
        for(int i = 0; i < test.get_size(); i++) {
            accuracy += predictions[i] == ground_truth[i];
        }
        return accuracy / test.get_size();
    } else {
        // Dynamic Time Warping
        vector<int> predictions;
        for(int i = 0; i < test.get_size(); i++) {
            vector<double> distances;
            for(int j = 0; j < train.get_size(); j++) {
                double distance = TimeSeriesDataset::dtw(test.get_ts(i), train.get_ts(j));
                distances.push_back(distance);
            }
            vector<int> indices(distances.size());
            iota(indices.begin(), indices.end(), 0);
            sort(indices.begin(), indices.end(), [&distances](int i1, int i2) {return distances[i1] < distances[i2];});
            int count = 0;
            for(int j = 0; j < k; j++) {
                count += ground_truth[indices[j]];
            }
            predictions.push_back(count > k/2);
        }
        double accuracy = 0;
        for(int i = 0; i < test.get_size(); i++) {
            accuracy += predictions[i] == ground_truth[i];
        }
        return accuracy / test.get_size();
    }
    return 0;
}