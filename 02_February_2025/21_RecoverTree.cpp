// https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/?envType=daily-question&envId=2025-02-22

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

 class Solution {
    void f(string& traversal, int l, int r, int level, TreeNode*& root) {
        int l1 = -1, r1 = -1, l2 = -1, r2 = -1;
        int n = traversal.size();
        while (l <= r) {
            if (traversal[l] == '-') {
                int cnt = 0;
                int start = l;
                while (l < n && traversal[l] == '-') {
                    cnt++;
                    l++;
                }
                if (cnt == level) {
                    if (l1 == -1) {
                        l1 = l;
                    } else {
                        l2 = l;
                        r1 = l2 - 1;
                        
                    }
                }
            } else {
                l++;
            }
        }

        if (l1 == -1) return;

        if (r1 == -1) {
            r1 = r;
            int num = 0;
            while (l1 < n && isdigit(traversal[l1])) {
                num = num * 10 + (traversal[l1] - '0');
                l1++;
            }
            TreeNode* temp = new TreeNode(num);
            root->left = temp;
            f(traversal, l1, r1, level + 1, root->left);
        } else if (r2 == -1) {
            int num1 = 0, num2 = 0;
            while (l1 < n && isdigit(traversal[l1])) {
                num1 = num1 * 10 + (traversal[l1] - '0');
                l1++;
            }
            while (l2 < n && isdigit(traversal[l2])) {
                num2 = num2 * 10 + (traversal[l2] - '0');
                l2++;
            }

            TreeNode* temp1 = new TreeNode(num1);
            root->left = temp1;
            f(traversal, l1, r1, level + 1, root->left);

            TreeNode* temp2 = new TreeNode(num2);
            root->right = temp2;
            f(traversal, l2, r, level + 1, root->right);
        }
    }

public:
    TreeNode* recoverFromPreorder(string traversal) {
        int n = traversal.size();
        int num = 0, i = 0;
        while (i < n && isdigit(traversal[i])) {
            num = num * 10 + (traversal[i] - '0');
            i++;
        }

        TreeNode* root = new TreeNode(num);
        f(traversal, i, n - 1, 1, root);
        return root;
    }
};

int main () {
    
    return 0;
}
