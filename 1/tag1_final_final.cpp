#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric> 
#include <unordered_map>

using namespace std;

int main() {
    vector<int> leftList, rightList;
    int left, right;

    // Einlesen der Daten
    while (cin >> left >> right) {
        leftList.push_back(left);
        rightList.push_back(right);
    }

    // Sortieren der Listen
    sort(leftList.begin(), leftList.end());
    sort(rightList.begin(), rightList.end());

    // Berechnung des Gesamtabstands mit std::transform und std::accumulate
    int totalDistance = std::inner_product(leftList.begin(), leftList.end(), rightList.begin(), 0,
                                          std::plus<>(), [](int left, int right) { return abs(left - right); });

    // Berechnung des Ähnlichkeitswerts mit einer Hashmap
    unordered_map<int, int> rightListCounts;
    for (int num : rightList) {
        rightListCounts[num]++;
    }

    int similarityScore = 0;
    for (int num : leftList) {
        if (rightListCounts.count(num) > 0) {
            similarityScore += num * rightListCounts[num];
        }
    }

    // Ausgabe der Ergebnisse
    cout << "Part 1: " << totalDistance << endl;
    cout << "Part 2: " << similarityScore << endl;

    return 0;
}