// https://leetcode.com/problems/redundant-connection/?envType=daily-question&envId=2025-01-29

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
    void dfs(int node,int parent ,vector<vector<int>> &adj,vector<int> &vis,vector<int> &curr,unordered_set<int> &ans){
        if(!ans.empty()) return ;
        if(vis[node]){
            for(int i=0;i<curr.size();i++){
                if(curr[i]!=node) continue;
                else{
                   for(;i<curr.size();i++){
                    ans.insert(curr[i]);
                   }
                }
            }
            return ;
        }
        vis[node]=1;
        curr.push_back(node);
        for(auto it:adj[node]){
            if(it==parent) continue;
            dfs(it,node,adj,vis,curr,ans);
        }
        curr.pop_back();
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> adj(n+1);
        adj[0]={};
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n+1,0);
        vector<int> curr;
        unordered_set<int> ans;
        dfs(1,-1,adj,vis,curr,ans);
        for(int j=n-1;j>=0;j--){
            int u=edges[j][0],v=edges[j][1];
            if(ans.find(u)!=ans.end() && ans.find(v)!=ans.end() ) return {u,v};
        }
        return {-1,-1};
    }
};

int main () {
    
    return 0;
}
