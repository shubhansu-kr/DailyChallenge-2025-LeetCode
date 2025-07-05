// https://leetcode.com/problems/find-lucky-integer-in-an-array/?envType=daily-question&envId=2025-07-05

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
    int findLucky(vector<int>& arr) {
        int freq[501] = {0};
        for (int no : arr) ++freq[no];
        for (int i = 500; i >= 0; --i) {
            if (!freq[i]) continue;
            if (freq[i] == i) return i;
        }
        return -1;
    }
};

int main () {
    
    return 0;
}