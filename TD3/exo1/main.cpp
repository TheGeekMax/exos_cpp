#include <iostream>
#include <vector>
#include <map>

using namespace std ;

void countFrequencyBruteForce(const vector<int>& numbers) {
    vector <int> visited;
    for (int i = 0; i < numbers.size(); i++) {
        if (find(visited.begin(), visited.end(), numbers[i]) != visited.end()) {
            continue;
        }
        visited.push_back(numbers[i]);
        int count = 1;
        for (int j = i + 1; j < numbers.size(); j++) {
            if (numbers[i] == numbers[j]) {
                count++;
            }
        }
        cout << numbers[i] << ": " << count << " times" << endl;
    }
}


map<int , int> countFrequencyOptimal(const vector<int>& numbers) {
    map<int , int> frequencyMap;
    for (int i = 0; i < numbers.size(); i++) {
        frequencyMap[numbers[i]]++;
    }
    return frequencyMap;
}

int main() {
    vector<int> numbers = {1, 2, 3, 2, 4, 1, 5, 5, 6};
    // Test countFrequencyBruteForce
    cout << "Frequency (Brute Force):" << endl;
    countFrequencyBruteForce (numbers);
    // Test countFrequencyOptimal
    cout << "\nFrequency (Optimal):" << endl;
    map<int , int> frequencyMapOptimal = countFrequencyOptimal ( numbers ) ;
    for (const auto& entry : frequencyMapOptimal) {
        cout << entry.first << ": " << entry.second << " times" << endl;
    }
    return 0 ;
}