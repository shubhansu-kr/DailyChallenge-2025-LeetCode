// https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/?envType=daily-question&envId=2025-03-28

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n=grid.size();int m=grid[0].size();
        int q_length=queries.size();
        vector<int>ans(q_length);
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        
        vector<pair<int,int>>sorted_q;
        for(int i=0;i<q_length;i++)
        {
            sorted_q.push_back({queries[i],i});

        }
        sort(sorted_q.begin(),sorted_q.end());
            priority_queue<pair<int, pair<int, int>>, 
                        vector<pair<int, pair<int, int>>>, 
                        greater<pair<int, pair<int, int>>>> pq;
            pq.push({grid[0][0],{0,0}});
            vis[0][0]=1;
        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};       
        int idx = 0;
        for(auto[q,q_index]:sorted_q)
        {
            while(!pq.empty() && pq.top().first < q)
            {
                int node=pq.top().first;
                int r=pq.top().second.first;
                int c=pq.top().second.second;
                cnt++;
                pq.pop();
                for (int i = 0; i < 4; i++) {
                    int dr = r + drow[i], dc = c + dcol[i];
                    if (dr >= 0 && dc >= 0 && dr < n && dc < m && !vis[dr][dc]) {
                        pq.push({grid[dr][dc], {dr, dc}});
                        vis[dr][dc] = 1;
                    }
                }
            }
            ans[q_index]=cnt;
        }  
        return ans;     
    }
};

int main () {
    
    return 0;
}