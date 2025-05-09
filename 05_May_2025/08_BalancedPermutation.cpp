// https://leetcode.com/problems/count-number-of-balanced-permutations/?envType=daily-question&envId=2025-05-09

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
    int countBalancedPermutations(string num) {
        int M = 1e9 + 7;
        int n = num.size();
        int sum = 0;
        vector <int> freq(10, 0);
        for(int i = 0; i < n; i++){
            sum += (num[i] - '0');
            freq[(num[i] - '0')]++;
        }

        if(sum & 1) return 0;
        
        vector <int> fact(n+1, 1);
        vector <int> inv(n+1, 1);
        vector <int> invFact(n+1, 1);

        for(int i = 1; i <= n; i++) fact[i] = (1LL* i * fact[i-1]) % M;
        for(int i = 2; i <= n; i++) inv[i] = (1LL * (M - M/i) * inv[M%i]) % M;
        for(int i = 2; i <= n; i++) invFact[i] = (1LL * invFact[i-1] * inv[i]) % M;

        int reqSum = sum/2;
        int k = n/2;

        vector <vector <int>> dp(k+1, vector <int> (sum+1, 0));
        dp[0][0] = 1;

        for (int i = 0; i < n; i++) {
            int x = num[i] - '0';
            for (int cnt = k; cnt >= 1; cnt--) {
                for (int currSum = reqSum; currSum >= x; currSum--) {
                    dp[cnt][currSum] = (dp[cnt][currSum] + dp[cnt - 1][currSum - x]) % M;
                }
            }
        }

        int ans = (1LL * fact[k]* (dp[k][reqSum]))%M;
        ans = (1LL* ans * fact[n-k]) % M;
        for(int c: freq) {
            if(c) ans = (1LL* ans * invFact[c])%M;
        }

        return ans;
    }
};

int main () {
    
    return 0;
}