// https://leetcode.com/problems/finding-3-digit-even-numbers/?envType=daily-question&envId=2025-05-12

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
    bool canForm(int i, unordered_map<int, int> mp){
        while(i>0){
            int t = i % 10;
            if(mp[t] == 0)
                return false;
            mp[t]--;
            i = i / 10;
        }
        return true;
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> arr;
        unordered_map<int, int> mp;
        for(auto it: digits)
            mp[it]++;

        for(int i=100; i<999; i+=2){
            if(canForm(i, mp)){
                arr.push_back(i);
            }
        }
        return arr;
    }
};

int main () {
    
    return 0;
}