// https://leetcode.com/problems/count-largest-group/?envType=daily-question&envId=2025-04-23

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

// Arraylist, hashmap, list, priority queue
// collections library

class Solution {
public:

    int countLargestGroup(int n) {
        unordered_map<int, int> m;
        for (int i = 1; i <= n; i++) {
            int sum = 0;
            int num = i;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            m[sum]++;
        }
        int maxCount = 0;
        for (auto& [key, value] : m) {
            maxCount = max(maxCount, value);
        }
        int count = 0;
        for (auto& [key, value] : m) {
            if (value == maxCount) {
                count++;
            }
        }
        return count;
    }
};

int main () {
    
    return 0;
}