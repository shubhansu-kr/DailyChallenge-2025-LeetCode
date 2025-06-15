// https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/?envType=daily-question&envId=2025-06-15

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
    int maxDiff(int num) {
        string numStr = to_string(num);
        set<char> uniqueDigits(numStr.begin(), numStr.end());
        int maxVal = num, minVal = num;

        for (char digit : uniqueDigits) {
            for (char newDigit = '0'; newDigit <= '9'; ++newDigit) {
                if (numStr[0] == digit && newDigit == '0') continue;
                string newNumStr = numStr;
                replace(newNumStr.begin(), newNumStr.end(), digit, newDigit);
                int newNum = stoi(newNumStr);
                maxVal = max(maxVal, newNum);
                minVal = min(minVal, newNum);
            }
        }

        return maxVal - minVal;
    }
};

int main () {
    
    return 0;
}