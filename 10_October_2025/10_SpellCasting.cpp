// https://leetcode.com/problems/maximum-total-damage-with-spell-casting/?envType=daily-question&envId=2025-10-11   

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
    long long dp[100001];
    
    long long k(int i, vector<int>& v) {
        if (i >= v.size()) return 0;
        if (dp[i] != -1) return dp[i];
        
        long long totalDamage = 0;
        int currentDamage = v[i];
        int j = i;
        
        while (j < v.size() && v[j] == currentDamage) {
            totalDamage += v[j];
            j++;
        }
        
        while (j < v.size() && (v[j] == currentDamage + 1 || v[j] == currentDamage + 2)) {
            j++;
        }
        
        long long take = totalDamage + k(j, v);
        
        int next = i;
        while (next < v.size() && v[next] == currentDamage) {
            next++;
        }
        long long skip = k(next, v);
        
        return dp[i] = max(take, skip);
    }
    
    long long maximumTotalDamage(vector<int>& power) {
        memset(dp, -1, sizeof(dp));
        sort(power.begin(), power.end());
        return k(0, power);
    }
};

int main () {
    
    return 0;
}