// https://leetcode.com/problems/zero-array-transformation-iii/?envType=daily-question&envId=2025-05-22

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
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        priority_queue<int,vector<int>,greater<int>> used_Query; 
        priority_queue<int> availableQuery;
        sort(queries.begin(),queries.end());
        int applied_Count = 0;
        int queryIndex = 0;
        
        for(int i=0;i<n;i++){
            while(queryIndex < queries.size() && queries[queryIndex][0] == i){
                availableQuery.push(queries[queryIndex][1]);
                queryIndex++;
            }
            nums[i] -= used_Query.size();
            while(nums[i] > 0 && !availableQuery.empty() && availableQuery.top()>=i){
                used_Query.push(availableQuery.top());
                availableQuery.pop();
                nums[i]--;
                applied_Count++;
            }
            if(nums[i]>0) return -1;

            while(!used_Query.empty() && used_Query.top() == i){
                used_Query.pop();
            }
        }
        return queries.size() - applied_Count;
    }
};

int main () {
    
    return 0;
}