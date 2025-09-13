// https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/?envType=daily-question&envId=2025-09-13

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
    int maxFreqSum(string s) {
        vector<int> freq = vector<int>(26,0);
        vector<bool> isVowel = vector<bool>(26,false);
        string vowels = "aeiou";
        for(auto &c:vowels){
            isVowel[c-'a']=true;
        }
        for(auto &c:s){
            freq[c-'a']++;
        }
        int freq1 = 0, freq2 = 0;
        for(int i = 0; i<26; ++i){
            if(isVowel[i]){
                freq1 = max(freq1, freq[i]);
            }else{
                freq2 = max(freq2, freq[i]);
            }
        }
        return freq1+freq2;
    }
};

int main () {
    
    return 0;
}