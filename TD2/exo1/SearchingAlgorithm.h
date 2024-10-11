//
// Created by Maxime Sanciaume on 11/10/2024.
//

#ifndef SEARCHINGALGORITHM_H
#define SEARCHINGALGORITHM_H
#include <vector>

using namespace std;

class SearchingAlgorithm {
public:
    // for stats
    int numberComparisons;
    static int totalSearch;
    static int totalComparisons;
    static double averageComparisons;

    SearchingAlgorithm() = default;
    virtual int search(const vector<int> &v,int target) = 0;
    void displaySearchResults(ostream &o, int target, int index);
};

//implements differents algorithm

class LinearSearch : public SearchingAlgorithm {
public:
    int search(const vector<int> &v, int target) override;
};

class JumpSearch : public SearchingAlgorithm {
public:
    int search(const vector<int> &v, int target) override;
};

class BinarySearch : public SearchingAlgorithm {
public:
    int search(const vector<int> &v, int target) override;
};

#endif //SEARCHINGALGORITHM_H
