#include <iostream>
#include <vector>
#include <random>
#include <time.h>

#include "SearchingAlgorithm.h"

using namespace std;

void random_shuffle(vector<int> &v) {
    //shuffle
    for (int i = 0; i < v.size(); i++) {
        int j = rand() % v.size();
        swap(v[i], v[j]);
    }
}

int main(){
    srand(time(NULL));
    //generate list
    vector<int> v;
    for (int i = 0; i < 100; i++) {
        v.push_back(i);
    }

    //randomize list v
    random_shuffle(v);

    //test linear search
    LinearSearch linearSearch;
    int target = 50;
    int index = linearSearch.search(v, target);
    linearSearch.displaySearchResults(cout, target, index);

    //test jump search
    JumpSearch jumpSearch;
    target = 50;
    index = jumpSearch.search(v, target);
    jumpSearch.displaySearchResults(cout, target, index);

    //test binary search
    BinarySearch binarySearch;
    target = 50;
    index = binarySearch.search(v, target);
    binarySearch.displaySearchResults(cout, target, index);

}
