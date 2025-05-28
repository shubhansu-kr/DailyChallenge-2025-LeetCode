// https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/?envType=daily-question&envId=2025-05-28

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
    int helper(int node, unordered_map<int,vector<int>>& adj, int max_count){
        pair<int,int> p;
        p.first = node;
        p.second = 0;

        queue<pair<int,int>>q;
        q.push(p);

        int n = adj.size();

        vector<int>visited(n, 0);

        visited[node] = 1;

        int ans = 0;

        while(q.size()){
            auto front = q.front();
            q.pop();
            int node = front.first;
            int dist = front.second;

            if(dist<max_count){
                for(auto neig : adj[node]){
                    if(!visited[neig]){
                        visited[neig] = 1;
                        q.push({neig, dist+1});
                        ans++;
                    }
                }
            }
        }
        return ans + 1;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& v1, vector<vector<int>>& v2, int k) {
        int n = -1;

        int nn = -1;

        unordered_map<int,vector<int>> adj1;
        unordered_map<int,vector<int>> adj2;

        for(int i = 0;i<v1.size();i++){
            int s = v1[i][0];
            int d = v1[i][1];
            adj1[s].push_back(d);
            adj1[d].push_back(s);
            n = max(n,s);
            n = max(n,d);
        }

        for(int i = 0;i<v2.size();i++){
            int s = v2[i][0];
            int d = v2[i][1];
            adj2[s].push_back(d);
            adj2[d].push_back(s);
            nn = max(nn,s);
            nn = max(nn,d);
        }

        vector<int>ans;

        int maxi = INT_MIN; 

        if(k>0){
            for(int i=0;i<=nn;i++){
                maxi = max(maxi, helper(i,adj2,k-1));
            }
        }

        for(int i = 0;i<=n;i++){
            int selfCount = helper(i,adj1,k);
            ans.push_back(selfCount + (maxi != INT_MIN ? maxi : 0));
        }

        return ans;
    }
};

int main () {
    
    return 0;
}