// https://leetcode.com/problems/finding-pairs-with-a-certain-sum/?envType=daily-question&envId=2025-07-06

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class FindSumPairs {
private:
    vector<int> nums1,nums2;
    unordered_map<int,int> freq2;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1=nums1;
        this->nums2=nums2;
        for(int num:nums2){
            freq2[num]++;
        }
    }
    
    void add(int index, int val) {
        int oldval=nums2[index];
        freq2[oldval]--;
        nums2[index]+=val;
        freq2[nums2[index]]++;
    }
    
    int count(int tot) {
        int count=0;
        for(int x:nums1){
            int y=tot-x;
            if(freq2.count(y)){
                count+=freq2[y];
            }

        }
        return count;
        
    }
};

int main () {
    
    return 0;
}