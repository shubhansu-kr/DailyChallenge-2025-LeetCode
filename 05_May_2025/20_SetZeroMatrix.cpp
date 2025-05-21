// https://leetcode.com/problems/set-matrix-zeroes/?envType=daily-question&envId=2025-05-21

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
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> columntomakezero;
        set<int> rowtomakezero;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    columntomakezero.insert(j);
                    rowtomakezero.insert(i);
                }
            }
        }
        for(auto&element:columntomakezero){
            for(int i=0;i<matrix.size();i++){
                matrix[i][element]=0;
            }
        }
        for(auto&element:rowtomakezero){
            for(int i=0;i<matrix[0].size();i++){
                matrix[element][i]=0;
            }
        }   
    }
};

int main () {
    
    return 0;
}