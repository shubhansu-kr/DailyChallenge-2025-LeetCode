// https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/?envType=daily-question&envId=2025-05-10

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
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        long long countZeros1 = count_if(nums1.begin(), nums1.end(),   
        [&](int a){sum1 += a;
                        return a == 0;});
        long long countZeros2 = count_if(nums2.begin(), nums2.end(),   
        [&](int a){
            sum2 += a;
            return a == 0;});


        if(countZeros1 == 0 and (sum1 < sum2 or countZeros2 > sum1-sum2) or
            countZeros2 == 0 and (sum1 > sum2 or countZeros1 > sum2-sum1))
        return -1;

        return max(sum1 + countZeros1, sum2 + countZeros2);
    }
};

int main () {
    
    return 0;
}