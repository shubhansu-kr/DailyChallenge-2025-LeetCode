// https://leetcode.com/problems/find-closest-node-to-given-two-nodes/?envType=daily-question&envId=2025-05-30

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
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> visited(n, -1);

        for (int i = 0; i < n; ++i)
        {
            if (node1 == node2) 
                return node1;
            else if (visited[node1] == 2 && visited[node2] == 1)
                return min(node1, node2);
            else if (visited[node2] == 1) 
                return node2;
            else if (visited[node1] == 2) 
                return node1;

            visited[node1] = 1;
            visited[node2] = 2;

            if (edges[node1] != -1) node1 = edges[node1];
            if (edges[node2] != -1) node2 = edges[node2];
        }
        return -1;
    }
};

int main () {
    
    return 0;
}