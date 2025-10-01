// https://leetcode.com/problems/water-bottles/?envType=daily-question&envId=2025-10-01

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
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles;
        while(numBottles>=numExchange){
            numBottles-=numExchange-1;
            ans++;
        }
        return ans;
    }
};

int main () {
    
    return 0;
}