// https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/?envType=daily-question&envId=2025-02-21q

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class FindElements {
private:
    std::unordered_set<int> recoveredValues;

    void recoverTree(TreeNode* root, int val) {
        if (!root) return;
        root->val = val;
        recoveredValues.insert(val);
        recoverTree(root->left, 2 * val + 1);
        recoverTree(root->right, 2 * val + 2);
    }

public:
    FindElements(TreeNode* root) {
        if (root) {
            recoverTree(root, 0);
        }
    }
    
    bool find(int target) {
        return recoveredValues.count(target);
    }
};

int main () {
    
    return 0;
}
