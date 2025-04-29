// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/?envType=daily-question&envId=2025-04-29

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
        long long countSubarrays(vector<int>& A, int k) {
        int a = *max_element(A.begin(), A.end()), n = A.size(), cur = 0, i = 0;
        long long res = 0;
        for (int j = 0; j < n; ++j) {
            cur += A[j] == a;
            while (cur >= k)
                cur -= A[i++] == a;
            res += i;
        }
        return res;
    }
};

int main () {
    
    return 0;
}