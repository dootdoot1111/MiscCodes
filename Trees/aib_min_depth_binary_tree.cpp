#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void helper(TreeNode* root, int depth, int &minD)
{
    if(!root)
        return;
    
    if(!root->left && !root->right && minD > depth)
    {
        minD = depth;
    }
    
    else
    {
        helper(root->left, depth+1, minD);
        helper(root->right, depth+1, minD);
    }
}

int minDepth(TreeNode* A) {
    
    int ret = INT_MAX;
    helper(A, 1, ret);
    
    return ret;
    
}