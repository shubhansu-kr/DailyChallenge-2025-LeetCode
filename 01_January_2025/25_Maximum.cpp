// https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/?envType=daily-question&envId=2025-01-26

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
    int maximumInvitations(vector<int>& fav) {
        int n = fav.size(), maxCycle = 0, pairChains = 0;
        queue<int> q; 
        vector<bool> vis(n); 
        vector<int> inDeg(n), chainLen(n); 
        
        for (int x : fav) inDeg[x]++;
        
        for (int i = 0; i < n; ++i) 
            if (!inDeg[i]) q.push(i);
        
        while (!q.empty()) {
            int u = q.front(); q.pop();
            vis[u] = true; 
            int nbr = fav[u]; 
            chainLen[nbr] = max(chainLen[nbr], chainLen[u] + 1);
            if (--inDeg[nbr] == 0) q.push(nbr); 
        }
        
        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;
            
            int cycleLen = 0, u = i;
            while (!vis[u]) {
                vis[u] = true;
                u = fav[u];
                cycleLen++;
            }
            
            if (cycleLen == 2) 
                pairChains += 2 + chainLen[i] + chainLen[fav[i]];
            else 
                maxCycle = max(maxCycle, cycleLen);
        }
        
        return max(maxCycle, pairChains);
    }
};

int main () {
    
    return 0;
}
