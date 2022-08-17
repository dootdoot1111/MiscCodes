#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
bool helper(TreeNode* aNode, TreeNode* bNode)
{
    if(!aNode && !bNode)
    {
        return true;
    }
    
    if(!aNode || !bNode)
    {
        return false;
    }
    
    if(aNode->val == bNode->val)
    {
        return helper(aNode->left, bNode->left) && helper(aNode->right, bNode->right);
    }
    
    return false;
}
 
int isSameTree(TreeNode* A, TreeNode* B) {
    
    return helper(A, B);
    
}
