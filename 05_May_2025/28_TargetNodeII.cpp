// https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii/?envType=daily-question&envId=2025-05-29

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
    vector<bool> find_even(const vector<vector<int>>& edges, int n){
        vector<vector<int>> graph(n);
        for (auto& e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<bool> evens(n, false);
        queue<tuple<int, int, bool>> q;
        q.emplace(0, -1, true);
        while (!q.empty()){
            auto [node, parent, is_even] = q.front();
            q.pop();
            evens[node] = is_even;
            for (int child : graph[node]){
                if (child != parent){
                    q.emplace(child, node, !is_even);
                }
            }
        }
        return evens;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n1 = edges1.size() + 1;
        int n2 = edges2.size() + 1;
        vector<bool> even1 = find_even(edges1, n1);
        vector<bool> even2 = find_even(edges2, n2);
        int total1 = count(even1.begin(), even1.end(), true);
        int total2 = count(even2.begin(), even2.end(), true);
        int mx = max(total2, n2 - total2);
        vector<int> ans(n1);
        for (int i = 0; i < n1; i++){
            ans[i] = mx + (even1[i] ? total1 : n1 - total1);
        }
        return ans;

    }
};

int main () {
    
    return 0;
}