// https://leetcode.com/problems/shifting-letters-ii/?envType=daily-question&envId=2025-01-05

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
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
       int n = s.size();
        vector<int> shiftArray(n + 1, 0); 
        
        for (const auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];
            
            if (direction == 1) {
                shiftArray[start] += 1;
                shiftArray[end + 1] -= 1;
            } else {
                shiftArray[start] -= 1;
                shiftArray[end + 1] += 1;
            }
        }
        
        for (int i = 1; i <= n; i++) {
            shiftArray[i] += shiftArray[i - 1];
        }
        
        for (int i = 0; i < n; i++) {
            int shift = shiftArray[i] % 26; 
            int newChar = s[i] - 'a' + shift;
            
            if (newChar < 0) {
                newChar += 26; 
            }
            s[i] = 'a' + (newChar % 26); 
        }
        
        return s;
    }
};

int main () {
    
    return 0;
}
