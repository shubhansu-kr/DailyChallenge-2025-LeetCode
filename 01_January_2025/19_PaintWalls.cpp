// https://leetcode.com/problems/first-completely-painted-row-or-column/?envType=daily-question&envId=2025-01-20

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
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        pair<int,int> p={0,0};
        vector<pair<int,int>> v(m*n+1, p);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                pair<int,int> p1 = {i,j};
                v[mat[i][j]] = p1;
            }
        }

        vector<int> row(m, 0);
        vector<int> col(n, 0);
        int i=0;
        for( i=0;i<arr.size();i++){
            int a = arr[i];
            pair<int,int> temp = v[a];
            int r1 = temp.first;
            int r2 = temp.second;

            row[r1]++;
            col[r2]++;
            if(row[r1]==n || col[r2]==m){
                return i;
            }
        }

        return arr.size();
    }
};

int main () {
    
    return 0;
}
