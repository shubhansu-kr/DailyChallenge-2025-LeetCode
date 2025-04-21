// https://leetcode.com/problems/count-the-hidden-sequences/?envType=daily-question&envId=2025-04-21

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int minPrefixSum = 0, maxPrefixSum = 0;
        int currentSum = 0;

        for(const int& diff : differences) {
            currentSum += diff;
            minPrefixSum = min(minPrefixSum, currentSum);
            maxPrefixSum = max(maxPrefixSum, currentSum); 
            if (maxPrefixSum - minPrefixSum > upper - lower) {
                return 0;
            }
        }
        return (upper - lower) - (maxPrefixSum - minPrefixSum) + 1;
    }
};

int main () {
    
    return 0;
}