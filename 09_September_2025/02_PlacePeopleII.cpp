// https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/?envType=daily-question&envId=2025-09-03

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
    int numberOfPairs(vector<vector<int>>& points) {

        sort(points.begin(), points.end(), [](auto &a, auto &b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        int n = points.size();
        vector<int> y(n);
        for (int i = 0; i < n; i++) {
            y[i] = points[i][1];
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int ya = y[i];
            int ll = INT_MIN;
            for(int j=i+1;j<n;j++){
                int yb = y[j];
                if(ya >= yb && yb>ll){
                ans++;
                ll = yb;
                }
                if(yb == ya)break;
            }
    
            }
        
        return ans;
    }
};

int main () {
    
    return 0;
}