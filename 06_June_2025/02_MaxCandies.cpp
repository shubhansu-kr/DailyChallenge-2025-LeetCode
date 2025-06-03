// https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/?envType=daily-question&envId=2025-06-03

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
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        int ans = 0;
        vector<bool> avlKeys(n,false);
        vector<bool> avlBoxes(n,false);

        queue<int> q;
        for(int i=0;i<initialBoxes.size();i++){
            if(status[initialBoxes[i]]==1) q.push(initialBoxes[i]);
            else avlBoxes[initialBoxes[i]] = true;
        }

        while(!q.empty()){
            int box = q.front();
            q.pop();
            ans+=candies[box];
            for(auto key: keys[box]){
                if(avlBoxes[key]){
                    q.push(key);
                    avlBoxes[key] = false;
                } else {
                    avlKeys[key] = true;
                }
            }
            for(auto cb: containedBoxes[box]){
                if(avlKeys[cb] || status[cb]==1){
                    q.push(cb);
                } else {
                    avlBoxes[cb] = true;
                }
            }
        }
        return ans;
    }
};

int main () {
    
    return 0;
}