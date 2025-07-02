// https://leetcode.com/problems/find-the-original-typed-string-ii/?envType=daily-question&envId=2025-07-02

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
    static constexpr int resk = 1e9+7;
    int possibleStringCount(string& word, int k) {
        const int n=word.size();
        if (n<k) return 0;
        if (n==k) return 1;
        vector<int> seg={1};
        for (int i=1; i<n; i++)
            if (word[i]==word[i-1]) seg.back()++;
            else seg.push_back(1);
        const int m=seg.size();
        long long total=1;
        bool takeMod=0;
        for(int x: seg){
            total*=x;
            if (total>=resk) {
                total%=resk;
                takeMod=1;
            }
        }
        if (total==1 && !takeMod) return 1; 
        if (k<=m) return total;
        int sks = k-m-1;
        long long dp[2][2000]={0}, prefix[2001]={0};
        dp[0][0]=1;
        for (int j=0; j<m; j++) {
            const int s=seg[j];
            for (int i=0; i<=sks; i++){
                prefix[i+1]=(prefix[i]+dp[j&1][i])%resk;
                int L=max(0, i-(s-1)), R=i;
                dp[(j+1)&1][i]=(prefix[R+1]-prefix[L]+resk)%resk;
            }
        }
        long long ksus=0;
        for (long long x : dp[m&1])
            ksus=(ksus+x)%resk;
        return (total-ksus+resk) % resk;
    }
};

int main () {
    
    return 0;
}