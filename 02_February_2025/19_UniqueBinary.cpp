// https://leetcode.com/problems/find-unique-binary-string/?envType=daily-question&envId=2025-02-20

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
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = "";

        for (int i = 0; i < nums.size(); ++i) {
            char currentChar = nums[i][i];
            char oppositeChar = (currentChar == '0') ? '1' : '0';

            ans += oppositeChar;
        }
        return ans;
    }
};

int main () {
    
    return 0;
}
