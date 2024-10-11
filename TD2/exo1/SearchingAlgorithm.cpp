//
// Created by Maxime Sanciaume on 11/10/2024.
//

#include "SearchingAlgorithm.h"
#include <iostream>
#include <vector>

using namespace std;

int SearchingAlgorithm::totalSearch = 0;
int SearchingAlgorithm::totalComparisons = 0;
double SearchingAlgorithm::averageComparisons = 0;

void SearchingAlgorithm::displaySearchResults(ostream &o, int target, int index) {
    //step 0 - calculate avg value
    totalSearch++;
    totalComparisons += numberComparisons;
    averageComparisons = (double) totalComparisons / totalSearch;

    //step 1 - display the target
    o << "Average number of comparisons: " << averageComparisons << endl;
    o << "found item " << target << " at index " << index << endl;
}

int LinearSearch::search(const vector<int> &v, int target) {
    //step 1 - initialize the number of comparisons
    numberComparisons = 0;

    //step 2 - search for the target
    for (int i = 0; i < v.size(); i++) {
        numberComparisons++;
        if (v[i] == target) {
            return i;
        }
    }

    return -1;
}

int JumpSearch::search(const vector<int> &v, int target) {
    //step 1 - initialize the number of comparisons
    numberComparisons = 0;

    //step 2 - calculate the jump size
    int jump = sqrt(v.size());

    //step 3 - search for the target
    int i = 0;
    while (i < v.size()) {
        numberComparisons++;
        if (v[i] == target) {
            return i;
        } else if (v[i] < target) {
            i += jump;
        } else {
            break;
        }
    }

    //step 4 - linear search
    for (int j = i - jump; j < v.size(); j++) {
        numberComparisons++;
        if (v[j] == target) {
            return j;
        }
    }

    return -1;
}

int BinarySearch::search(const vector<int> &v, int target) {
    //step 1 - initialize the number of comparisons
    numberComparisons = 0;

    //step 2 - search for the target
    int left = 0;
    int right = v.size() - 1;
    while (left <= right) {
        numberComparisons++;
        int mid = left + (right - left) / 2;
        if (v[mid] == target) {
            return mid;
        } else if (v[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}