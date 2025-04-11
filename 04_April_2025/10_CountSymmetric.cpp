// https://leetcode.com/problems/count-symmetric-integers/description/?envType=daily-question&envId=2025-04-11

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool check(int k) {
        vector<int> v;
        while(k) {
            v.push_back(k % 10);
            k  = k / 10;
        }
        if (v.size() % 2 != 0) return false;

        int left = 0, right = v.size()-1;
        int leftSum = 0, rightSum = 0;

        while(left < right) {
            leftSum += v[left];
            rightSum += v[right];

            left++;
            right--;
        }

        return leftSum == rightSum;
    }
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i = low; i <= high; ++i) {
            if (check(i)) ++ans;
        }
        return ans;
    }
};

int main () {
    
    return 0;
}