// https://leetcode.com/problems/minimum-deletions-to-make-string-k-special/?envType=daily-question&envId=2025-06-21

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
    int minimumDeletions(string word, int k) {
        
        unordered_map<char,int>freqmap; 
        for(char& ch: word){
            freqmap[ch]++;
        }
        
        vector<int>freqarr;
        for( auto& it: freqmap){
            freqarr.push_back(it.second);
        }

        sort(freqarr.begin(), freqarr.end());
        
        int deletions;
        int mindeletions=INT_MAX;
        
        for(int i=0; i<freqarr.size(); i++){
                deletions=0;
            int range_start=freqarr[i];
            int range_end=freqarr[i]+k;

            for(int j=0; j<i; j++){
                deletions +=freqarr[j];
            }
            for( int j=i; j<freqarr.size(); j++){
                if(freqarr[j]>(range_end)){
                    deletions+=freqarr[j]-range_end;
                }
            }
                mindeletions=min(mindeletions,deletions);

        }
        return mindeletions;
    }
};

int main () {
    
    return 0;
}