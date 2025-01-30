// https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups/?envType=daily-question&envId=2025-01-30

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
    bool isBp(unordered_map<int,vector<int>>& adj, vector<int>& color, int node, int col) {
        color[node] = col;
        for (auto &adjNode : adj[node]) {
            if (color[adjNode] == -1) {
                if (!isBp(adj, color, adjNode, 1 - col)) {
                    return false;
                }
            } else if (color[adjNode] == color[node]) {  
                return false;
            }
        }
        return true;
    }

    int BFS(unordered_map<int,vector<int>>& adj, int node, int n) {
        queue<int> q;
        vector<int> vis(n, 0);
        q.push(node);
        vis[node] = 1;
        int lvl = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int cur = q.front();
                q.pop();
                for (auto adjNode : adj[cur]) {
                    if (!vis[adjNode]) {
                        vis[adjNode] = 1;
                        q.push(adjNode);
                    }
                }
            }
            lvl++;
        }
        return lvl;
    }

    int maxComp(unordered_map<int,vector<int>>& adj, int node, vector<int>& vis) {
        queue<int> q;
        vector<int> componentNodes;
        q.push(node);
        vis[node] = 1;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            componentNodes.push_back(cur);
            for (auto adjNode : adj[cur]) {
                if (!vis[adjNode]) {
                    vis[adjNode] = 1;
                    q.push(adjNode);
                }
            }
        }

        int maxLevel = 0;
        for (auto x : componentNodes) {
            maxLevel = max(maxLevel, BFS(adj, x, vis.size()));
        }
        return maxLevel;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;

        for (auto &edge : edges) {
            int u = edge[0] - 1, v = edge[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(n, -1);
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!isBp(adj, color, i, 0)) {
                    return -1;  
                }
            }
        }

        int ans = 0;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                ans += maxComp(adj, i, vis);
            }
        }
        return ans;
    }
};

int main () {
    
    return 0;
}
