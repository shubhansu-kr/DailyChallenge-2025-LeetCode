// https://leetcode.com/problems/closest-prime-numbers-in-range/?envType=daily-question&envId=2025-03-07

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
    vector<int> closestPrimes(int left, int right) {
        vector<bool> v(1000005,true);
        v[1]=false;
        for(int i = 2;i<=sqrt(1000001);i++){
            if(!v[i]) continue;
            v[i]=1;
            for(int j = i+i;j<=1000001;j+=i){
                v[j]=0;
            }
        }
        int resl=-1,resr=-1;
        int ans = INT_MAX;
        for(int i = left ; i<=right;i++){
            if(v[i]){
                resl = i;
                break;
            }
        }
        if(resl==-1) return {-1,-1};
        int l=resl,r=-1;
        for(int i = l+1;i<=right;i++){
            if(v[i]){
                if(i-l<ans && r==-1){
                    ans = i-l;
                    resr = i;
                    r = i;
                }
                else if(r!=-1){
                    l = r;
                    r = i;
                    if(r-l<ans){
                        resr = r;
                        resl = l;
                        ans = r-l;
                    }

                }
            }
        }
        if(resl==-1 || resr==-1) return {-1,-1};
        return {resl,resr};
        
    }
};

int main () {
    
    return 0;
}
