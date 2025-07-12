// https://leetcode.com/problems/the-earliest-and-latest-rounds-where-players-compete/?envType=daily-question&envId=2025-07-12

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
    int mn,mx,fp,sp,dp[29][29][29];
    void rec(int s, int e, vector<int>curr, vector<int>adv, int roundNo) {
        if (s>e) {
            if(adv.size()<=1) return;
            curr=adv;
            sort(curr.begin(),curr.end());
            adv.clear();
            int fpp,spp;
            for(int i=0;i<curr.size();i++) {
                if (curr[i]==fp) fpp=i;
                if (curr[i]==sp) spp=i; 
            }
            if (dp[fpp][spp][roundNo+1]!=-1) {
                return;
            }
            dp[fpp][spp][roundNo+1]=0;
            rec(0,curr.size()-1,curr,adv, roundNo+1);
            return;
        }
        int i=s,j=e;
        if (i==j) {
            adv.push_back(curr[i]);
            rec(s+1,e,curr,adv,roundNo);
            adv.pop_back();
        } else {
            if((curr[i]==fp&&curr[j]==sp)||(curr[i]==sp&&curr[j]==fp)) {
                mn=min(mn,roundNo);
                mx=max(mx,roundNo);
                return;
            }
            if(curr[j]!=fp&&curr[j]!=sp) {
                adv.push_back(curr[i]);
                rec(s+1,e-1,curr,adv,roundNo);
                adv.pop_back();
            }
            if(curr[i]!=fp&&curr[i]!=sp) {
                adv.push_back(curr[j]);
                rec(s+1,e-1,curr,adv,roundNo);
                adv.pop_back();
            }
        }
        return;
    }

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        vector<int>curr,adv;
        for(int i=1;i<=n;i++) {
            curr.push_back(i);
        }
        mn=100,mx=0;
        fp=firstPlayer;
        sp=secondPlayer;
        memset(dp,-1,sizeof(dp));
        dp[firstPlayer-1][secondPlayer-1][1]=0;
        rec(0,n-1,curr,adv,1);
        return {mn,mx};
    }
};

int main () {
    
    return 0;
}