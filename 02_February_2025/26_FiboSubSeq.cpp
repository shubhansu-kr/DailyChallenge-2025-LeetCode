// https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/?envType=daily-question&envId=2025-02-27

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
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        int maxlen = 0 ;
        for(int i = 0 ; i < n-2 ; i++){
            for(int j = i+1 ; j < n -1 ; j++){
                int first = arr[i];
                int second = arr[j];
                int length = 0;
                int start = j+1;
                int end = n - 1;
                while(start<=end){
                    int mid = start + (end - start)/2;
                    if(first+second>arr[mid]){
                        start = mid + 1 ;
                    }
                    else if(first + second == arr[mid]){  
                        first = second;
                        second = arr[mid];
                        length++;
                        start = mid + 1;
                        end = n - 1 ;
                    }
                    else{
                        end = mid - 1 ;
                    }
                    
                }
                maxlen = max(maxlen , length);
            }
        }
        if(maxlen>0){
            return maxlen + 2 ;
        }
        return 0;
    }
};

int main () {
    
    return 0;
}
