// https://leetcode.com/problems/maximum-candies-allocated-to-k-children/?envType=daily-question&envId=2025-03-14

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
private:
    bool Distribute(vector<int>& candies, int candy, int k){
        long long count = 0;
        for (int c : candies){
            count += c / candy;
            if (count >= k)
                return true;
        }
        return false;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long total = accumulate(candies.begin(), candies.end(), 0LL);
        if (total < k)
            return 0;
        int left = 1, right = total / k;
        while (left < right){
            int mid = (left + right + 1) / 2;
            if (Distribute(candies, mid, k)){
                left = mid;
            } else {
                right = mid -1;
            }
        }
        return left;
    }
};
    

int main () {
    
    return 0;
}
