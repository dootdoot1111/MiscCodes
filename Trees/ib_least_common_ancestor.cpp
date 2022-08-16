#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


bool helper(TreeNode* root,int B,int C,TreeNode* &ans){
    if(!root)  return false;
    bool flag = root->val==B || root->val==C;
    bool l = helper(root->left,B,C,ans);
    bool r = helper(root->right,B,C,ans);
    if(flag && B==C)
        ans = root;
    if(((flag && l) || (flag && r) || (l && r)) && !ans)
        ans = root;
    return flag | l | r;
}

int lca(TreeNode* A, int B, int C) {
    
    TreeNode* ans = NULL;
    helper(A, B, C, ans);
    
    if(!ans)
    {
        return -1;
    }
    
    return ans->val;
}