// https://leetcode.com/problems/number-of-people-aware-of-a-secret/?envType=daily-question&envId=2025-09-09

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

#define Mod 1000000007
class Solution {
public:
    int peopleAwareOfSecret(int N, int delay, int forget) {
        vector<long long> dp(N+1,0ll);

        dp[0]=0;
        dp[1]=1;

        int sum = 0;
        for(int i=1;i<=N;i++)
        {
            if(dp[i]>0)
            {
                for(int j=i+delay;j<i+forget && j<=N;j++){
                    dp[j]+=dp[i]%Mod;
                    dp[j]=dp[j]%Mod;
                }
            }

            if(i>(N-forget))
                sum=(sum+dp[i])%Mod;
        }
        
        return sum;
    }
};

int main () {
    
    return 0;
}