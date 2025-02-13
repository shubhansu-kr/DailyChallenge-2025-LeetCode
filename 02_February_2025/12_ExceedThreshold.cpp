// https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/?envType=daily-question&envId=2025-02-13

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
    int minOperations(vector<int>& nums, int k) {
            
        priority_queue<long ,vector<long>,greater<long>>pq;
        for(auto it:nums){
            pq.push(it);
        }
        int cnt=0;
        while(pq.top()<k){
            int a;
            if(pq.size()>1){
                a=pq.top();
                pq.pop();
            }
            else{
                return cnt;
            }
            int b;
            if(pq.size()>=1){
                b=pq.top();
                pq.pop();
            }
            long long ans=(long long)min(a,b)*2+max(a,b);
            pq.push(ans);
            cnt++;
        }
        return cnt;
    }
};

int main () {
    
    return 0;
}
