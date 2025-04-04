// https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/?envType=daily-question&envId=2025-04-04

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    using info=pair<TreeNode*, TreeNode*>;
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (!root) return root;
        info q[1000];
        TreeNode* x2T[1001];
        int par[1001];
        int front=0, back=0;
        q[back++]={root, NULL};
        int d=0;
        int L=-1, R=-1;
        for( ; front!=back; d++){
            int qz=back-front;
            for(int i=0; i<qz; i++){
                auto [node, parent]=q[front++];
                int x=node->val;
                int y=(!parent)?-1:parent->val;
                par[x]=y;
                x2T[x]=node;
                if (i==0) L=x;
                if (i==qz-1) R=x;
                
                if (node->left) q[back++]={node->left, node};
                if (node->right) q[back++]={node->right, node};
            } 
        }
        if (L==R) return x2T[L];
        int s=L, t=R;
        while(s!=t){
            s=par[s];
            t=par[t];
        }
        return x2T[s];
    }
};

int main () {
    
    return 0;
}