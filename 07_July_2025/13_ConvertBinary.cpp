// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/?envType=daily-question&envId=2025-07-14

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

struct ListNode {
    int val;
    ListNode * next;
    ListNode():val(0), next(nullptr){}
    ListNode(int val):val(val), next(nullptr){}
    ListNode(int val, ListNode *next):val(val), next(next){}
};

class Solution {
public:
    int getDecimalValue(ListNode *head)
    {
        int num = head->val;
        head = head->next ;
        while (head != NULL)
        {
            num = num * 2 + head->val;
            head = head->next;
        }
        return num;
    }
};

int main () {
    
    return 0;
}