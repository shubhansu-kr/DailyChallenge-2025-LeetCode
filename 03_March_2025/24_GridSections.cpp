// https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/?envType=daily-question&envId=2025-03-25

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool checkValidCuts(int n,
                        std::vector<std::vector<int>>& sorted_rectangles) {

        std::sort(sorted_rectangles.begin(), sorted_rectangles.end(),
                    [](const std::vector<int>& p, const std::vector<int>& q) {
                        return p[0] == q[0] ? (p[2] < q[2]) : (p[0] < q[0]);
                    });

        int prev = sorted_rectangles[0][2];
        int max_end = prev;
        int cut_found = 0;
        for (const std::vector<int>& rectangle : sorted_rectangles) {
            if (prev >= max_end) {
                if (rectangle[0] == prev) {
                    if (++cut_found == 2) {
                        return true;
                    }
                }

                max_end = prev;
            }
            prev = rectangle[2];
        }

        // Check vertical cut.
        std::sort(sorted_rectangles.begin(), sorted_rectangles.end(),
                    [](const std::vector<int>& p, const std::vector<int>& q) {
                        return (p[1] == q[1]) ? (p[3] < q[3]) : (p[1] < q[1]);
                    });
        prev = sorted_rectangles[0][3];
        max_end = prev;
        cut_found = 0;
        for (const std::vector<int>& rectangle : sorted_rectangles) {
            if (prev >= max_end) {
                if (rectangle[1] == prev) {
                    if (++cut_found == 2) {
                        return true;
                    }
                }

                max_end = prev;
            }
            prev = rectangle[3];
        }

        return false;
    }
};

int main () {
    
    return 0;
}