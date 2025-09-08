// https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/?envType=daily-question&envId=2025-09-08

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
    vector<int> getNoZeroIntegers(int n) {
        int num = n;

        int start = 1;
        int end = n-1;

        while(start <= end){
            int n1 = start;
            int n2 = end;
            bool n1_0 = false;
            bool n2_0 = false;

            while(n1){
                if(n1%10 == 0){
                    n1_0 = true;
                    break;
                }
                n1 = n1 / 10;
            }

            while(n2){
                if(n2%10 == 0){
                    n2_0 = true;
                    break;
                }
                n2 = n2 / 10;
            }

            if(!n1_0 && !n2_0)
                return {start, end};

            start++;
            end--;
        }

        return {};
    }
};

int main () {
    
    return 0;
}