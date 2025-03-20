// https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/?envType=daily-question&envId=2025-03-20

#include <bits/stdc++.h>
using namespace std ;

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) { 
        return a[2] < b[2]; 
    }

    int find(int x, vector<int>& parent) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x], parent); // ✅ Path compression
    }

    void unionset(int u, int v, vector<int>& parent, vector<int>& rank, unordered_map<int, int>& componentCost, int weight) {
        u = find(u, parent);
        v = find(v, parent);
        
        if (u != v) {  // ✅ Merge components and update AND cost
            if (rank[u] < rank[v]) {
                parent[u] = v;
                componentCost[v] &= componentCost[u]; // Merge AND values
            } else if (rank[v] < rank[u]) {
                parent[v] = u;
                componentCost[u] &= componentCost[v]; // Merge AND values
            } else {
                parent[u] = v;
                rank[v]++;
                componentCost[v] &= componentCost[u]; // Merge AND values
            }
        }
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> rank(n, 0), parent(n);
        unordered_map<int, int> componentCost; // ✅ Track AND value for each component

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            componentCost[i] = INT_MAX; // Start with max so that AND can work properly
        }

        sort(edges.begin(), edges.end(), cmp);

        for (const auto& edge : edges) {
            int u = find(edge[0], parent);
            int v = find(edge[1], parent);
            int weight = edge[2];

            if (u != v) {
                unionset(u, v, parent, rank, componentCost, weight);
            }

            // Update component AND cost (bitwise AND of all edges in component)
            componentCost[find(u, parent)] &= weight;
        }

        vector<int> res(query.size());
        for (int i = 0; i < query.size(); i++) {
            int s = query[i][0];
            int t = query[i][1];

            if (find(s, parent) == find(t, parent)) {
                res[i] = componentCost[find(s, parent)];
            } else {
                res[i] = -1;
            }
        }

        return res;
    }
};

int main () {
    
    return 0;
}