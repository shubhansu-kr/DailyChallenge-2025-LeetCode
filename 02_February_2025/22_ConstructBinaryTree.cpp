// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/?envType=daily-question&envId=2025-02-23

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
    TreeNode* solve(int prestart, int poststart, int preend, vector<int>preorder, vector<int>postorder){
        if(prestart > preend){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[prestart]);
        if(prestart == preend){
            return root;
        }
        int nextNode = preorder[prestart+1];
        int j = poststart;
        while(postorder[j] != nextNode){
            j++;
        }
        int  nums = j-poststart+1;
        root->left = solve(prestart+1, poststart, prestart+nums, preorder, postorder);
        root->right = solve(prestart+nums+1, j+1, preend, preorder, postorder);
        return root;
    }   


    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        return solve(0, 0, n-1, preorder, postorder);
    }
};

int main () {
    
    return 0;
}
