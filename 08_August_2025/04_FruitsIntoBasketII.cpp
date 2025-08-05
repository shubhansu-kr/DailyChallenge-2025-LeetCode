// https://leetcode.com/problems/fruits-into-baskets-ii/?envType=daily-question&envId=2025-08-05

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
// Brute Force Approach
// Time Complexity: O(n^2)
// Space Complexity: O(1)
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();

        int unplacedFruit = 0;
        for (int i = 0; i < n; ++i) {
            unplacedFruit++;
            for(int j = 0; j < n; ++j) {
                if (fruits[i] <= baskets[j]) {
                    baskets[j] = 0;
                    unplacedFruit--;
                    break;
                }
            }
        }
        return unplacedFruit;
    }
};

int main () {
    
    return 0;
}