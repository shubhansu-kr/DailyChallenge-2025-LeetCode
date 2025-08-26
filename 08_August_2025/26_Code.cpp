// https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle/?envType=daily-question&envId=2025-08-26

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
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea = 0, maxDiag = 0;

        for (int i = 0; i < dimensions.size(); i++) {
            int l = dimensions[i][0];
            int w = dimensions[i][1];
            int currDiag = l * l + w * w;

            if (currDiag > maxDiag || (currDiag == maxDiag && l * w > maxArea)) {
                maxDiag = currDiag;
                maxArea = l * w;
            }
        }
        return maxArea;
    }
};

int main () {
    
    return 0;
}