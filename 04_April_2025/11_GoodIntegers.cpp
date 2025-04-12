// https://leetcode.com/problems/find-the-count-of-good-integers/?envType=daily-question&envId=2025-04-12

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        unordered_set<string> stOfPalind;
        int d = (n + 1) / 2; 
        int start = pow(10, d - 1);
        int end = pow(10, d) - 1;

        for (int i = start; i <= end; i++) {
            string leftHalf = to_string(i);
            string palindrome = "";
            if (n % 2 == 0) {
                string rightHalf = leftHalf;
                reverse(rightHalf.begin(), rightHalf.end());
                palindrome = leftHalf + rightHalf;
            } else {
                string rightHalf = leftHalf.substr(0, d - 1);
                reverse(rightHalf.begin(), rightHalf.end());
                palindrome = leftHalf + rightHalf;
            }

            long long kPalindrome = stoll(palindrome);
            if (kPalindrome % k != 0)
                continue;

            sort(palindrome.begin(), palindrome.end());
            stOfPalind.insert(palindrome);
        }

        vector<long long> factorial(11, 1);
        for (int i = 1; i <= 10; i++) {
            factorial[i] = factorial[i - 1] * i;
        }

        long long ans = 0;
        for (string str : stOfPalind) {
            vector<int> countOfDigitsInPalind(10, 0);

            for (char ch : str) {
                countOfDigitsInPalind[ch - '0']++;
            }

            int totalDigits = str.length();
            int zeroDigits = countOfDigitsInPalind[0];
            int nonZeroDigits = totalDigits - zeroDigits;

            long long permutations = nonZeroDigits * factorial[totalDigits - 1];

            for (int i = 0; i <= 9; i++) {
                permutations /= factorial[countOfDigitsInPalind[i]];
            }

            ans += permutations;
        }
        return ans;
    }
};

int main () {
    
    return 0;
}