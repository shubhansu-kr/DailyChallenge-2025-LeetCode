// https://leetcode.com/problems/largest-triangle-area/?envType=daily-question&envId=2025-09-27

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
    double largestTriangleArea(vector<vector<int>>& points) {
        double max_area = INT_MIN;
        int n = points.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k = j+1; k<n; k++){
                    int x1 = points[i][0], y1=points[i][1];
                    int x2 = points[j][0], y2=points[j][1];
                    int x3 = points[k][0], y3=points[k][1];
                    double area = 0.5 *abs ((x1)*(y2-y3) + (x2)*(y3-y1) + (x3)*(y1-y2));
                    max_area = max(max_area, area);
                }
            }
        }
        return max_area;
    }
};

int main () {
    
    return 0;
}