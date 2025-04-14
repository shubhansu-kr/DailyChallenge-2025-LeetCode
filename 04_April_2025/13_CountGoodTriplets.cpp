// https://leetcode.com/problems/count-good-triplets/?envType=daily-question&envId=2025-04-14

#include <bits/stdc++.h>
using namespace std ;

class Solution {
int mod(int a, int b)
    {
        return (a > b) ? (a - b) : (b - a);
    }

public:
    int countGoodTriplets(vector<int> &arr, int a, int b, int c)
    {
        int count = 0;
        for (int i = 0; i < arr.size() - 2; i++)
        {
            int j = i + 1;
            while (j < arr.size() - 1)
            {
                if (mod(arr[i], arr[j]) <= a)
                {
                    int k = j + 1;
                    while (k < arr.size())
                    {
                        if (mod(arr[j], arr[k]) <= b)
                        {
                            if (mod(arr[i], arr[k]) <= c)
                            {
                                count++;
                            }
                        }
                        k++;
                    }
                }
                j++;
            }
        }
        return count;
    }
};

int main () {
    
    return 0;
}