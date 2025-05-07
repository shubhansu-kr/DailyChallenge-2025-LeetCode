// https://leetcode.com/problems/find-minimum-time-to-reach-last-room-i/?envType=daily-question&envId=2025-05-07

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
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size();
        int n = moveTime[0].size(); 
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>, greater<>> minheap;
        vector<vector<int>> visited(m,vector<int>(n,-1));
        minheap.push({0,{0,0}});
        while(!minheap.empty()){
            auto it = minheap.top();
            minheap.pop();
            int value = it.first;
            int x = it.second.first;
            int y = it.second.second;
            if(x>0 && visited[x-1][y]==-1){
                if(moveTime[x-1][y]>value){
                    minheap.push({moveTime[x-1][y]+1,{x-1,y}});
                    visited[x-1][y] = moveTime[x-1][y]+1;
                }
                else{
                    minheap.push({value+1,{x-1,y}});
                    visited[x-1][y] =it.first+1;
                }
            
            }
                if(y>0 && visited[x][y-1]==-1){
                if(moveTime[x][y-1]>value){
                    minheap.push({moveTime[x][y-1]+1,{x,y-1}});
                    visited[x][y-1] = moveTime[x][y-1]+1;
                }
                else{
                    minheap.push({value+1,{x,y-1}});
                    visited[x][y-1] =it.first+1;
                }
            
            }
                if(x<m-1 && visited[x+1][y]==-1){
                if(moveTime[x+1][y]>value){
                    minheap.push({moveTime[x+1][y]+1,{x+1,y}});
                    visited[x+1][y] = moveTime[x+1][y]+1;
                }
                else{
                    minheap.push({value+1,{x+1,y}});
                    visited[x+1][y] =it.first+1;
                }
            }
                if(y<n-1 && visited[x][y+1]==-1){
                if(moveTime[x][y+1]>value){
                    minheap.push({moveTime[x][y+1]+1,{x,y+1}});
                    visited[x][y+1] = moveTime[x][y+1]+1;
                }
                else{
                    minheap.push({value+1,{x,y+1}});
                    visited[x][y+1] =it.first+1;
                }
            
            }
        }
        return visited[m-1][n-1];
    }
};

int main () {
    
    return 0;
}