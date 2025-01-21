// https://leetcode.com/problems/grid-game/?envType=daily-question&envId=2025-01-21

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
    long long gridGame(vector<vector<int>>& g) {
        int n= g[0].size();
        vector<long long> p1(n),p2(n);
        p1[0]=g[0][0],p2[0]=g[1][0];
        for(int i=1;i<n;i++){
            p1[i]= p1[i-1]+(long long)g[0][i];
            p2[i]= p2[i-1]+(long long)g[1][i];
        }

        long long res= LONG_LONG_MAX,x,y;

        for(int i=0;i<n;i++){
            x= i-1>=0? p2[i-1]:0;
            y= p1[n-1]-p1[i];
            res= min(res,max(x,y));
        }

        return res;

    }
};

int main () {
    
    return 0;
}
