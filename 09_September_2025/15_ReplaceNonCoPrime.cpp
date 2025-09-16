// https://leetcode.com/problems/replace-non-coprime-numbers-in-array/?envType=daily-question&envId=2025-09-16

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
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> s;
        s.push_back(nums[0]);
        int n=nums.size();
        for(int i=1;i<n;i++){
            int a=s.back(),b=nums[i];
            int gcdVal=std::gcd(a,b);
            if(gcdVal>1){
                s.pop_back();
                long long lcmVal=(1LL*a*b)/gcdVal;
                while(!s.empty()){
                    int top=s.back();
                    int gcdVal2=std::gcd(top,(int)lcmVal);
                    if(gcdVal2>1){
                        s.pop_back();
                        lcmVal=(1LL*top*lcmVal)/gcdVal2;
                    } else break;
                }
                s.push_back((int)lcmVal);
            } else {
                s.push_back(b);
            }
        }
        return s;
    }
};

int main () {
    
    return 0;
}