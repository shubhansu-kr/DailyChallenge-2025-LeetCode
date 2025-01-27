// https://leetcode.com/problems/course-schedule-iv/?envType=daily-question&envId=2025-01-27

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
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> isPrerequisite(numCourses, vector<bool>(numCourses, false));
        
        for (const auto& pre : prerequisites) {
            int u = pre[0], v = pre[1];
            isPrerequisite[u][v] = true;
        }
        
        for (int k = 0; k < numCourses; ++k) {
            for (int i = 0; i < numCourses; ++i) {
                for (int j = 0; j < numCourses; ++j) {
                    if (isPrerequisite[i][k] && isPrerequisite[k][j]) {
                        isPrerequisite[i][j] = true;
                    }
                }
            }
        }
        
        vector<bool> result;
        for (const auto& query : queries) {
            int u = query[0], v = query[1];
            result.push_back(isPrerequisite[u][v]);
        }
        
        return result;
    }
};

int main () {
    
    return 0;
}
