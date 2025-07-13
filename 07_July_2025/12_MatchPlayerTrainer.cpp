// https://leetcode.com/problems/maximum-matching-of-players-with-trainers/?envType=daily-question&envId=2025-07-13

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
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end(), greater<int>());
        sort(trainers.begin(), trainers.end(), greater<int>());
    
        int i = 0, j = 0, ans = 0;
        while(i < players.size() && j < trainers.size()) {
            if (trainers[j] < players[i]) {
                ++i;
            }
            else {
                ++i, ++j, ++ans;
            }
        }
        return ans;
    }
};

int main () {
    
    return 0;
}