// https://leetcode.com/problems/alice-and-bob-playing-flower-game/description/?envType=daily-question&envId=2025-08-29

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
    long long flowerGame(int n, int m) {

        long long odd1 = (n+1)/2;
        long long even1 = n/2;
        long long odd2 = (m+1)/2;
        long long even2 = m/2;
        long long ans = odd1*even2 + even1*odd2;
        return ans;
    }
};

int main () {
    
    return 0;
}