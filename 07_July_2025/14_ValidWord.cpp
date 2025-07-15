// https://leetcode.com/problems/valid-word/?envType=daily-question&envId=2025-07-15

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
    bool isValid(string word) {
        if (word.size() < 3)
            return false;

        bool vowel = false;
        bool cons = false;

        for (int i = 0; i < word.size(); i++) {
            if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' ||
                word[i] == 'o' || word[i] == 'u' || word[i] == 'A' ||
                word[i] == 'E' || word[i] == 'I' || word[i] == 'O' ||
                word[i] == 'U') {
                vowel = true;
            }
            else if (word[i] >= '0' && word[i] <= '9') {
                continue;
            }
            else if ((word[i] >= 'a' && word[i] <= 'z') ||
                        (word[i] >= 'A' && word[i] <= 'Z')) {
                cons = true;
            }
            else {
                return false;
            }
        }

        return vowel && cons;
    }
};

int main () {
    
    return 0;
}