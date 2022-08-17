#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int hasPathSum(TreeNode* A, int B) {
    
    if(!A)
    {
        return 0;
    }
    
    if(!A->left && !A->right)
    {
        return B - A->val == 0;
    }
    
    return hasPathSum(A->left, B-A->val) || hasPathSum(A->right, B-A->val);
    
}