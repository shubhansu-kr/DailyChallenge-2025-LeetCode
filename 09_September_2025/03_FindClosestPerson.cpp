// https://leetcode.com/problems/find-closest-person/?envType=daily-question&envId=2025-09-04

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
    int findClosest(int x, int y, int z) {
        return abs(x-z)==abs(y-z)?0:2-(abs(x-z)<abs(y-z));
    }
};

int main () {
    
    return 0;
}