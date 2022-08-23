#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void helper(TreeNode* root, vector<int> &tree)
{
    if(!root)
        return;
    
    helper(root->left, tree);
    tree.push_back(root->val);
    helper(root->right, tree);
}

vector<int> recoverTree(TreeNode* A) {
    
    vector<int> tree, ret;
    helper(A, tree);
    
    int n = tree.size();
    
    vector<int> sortedTree(tree.begin(), tree.end());
    sort(sortedTree.begin(), sortedTree.end());
    
    for(int i = 0; i < n; i++)
    {
        if(tree[i] != sortedTree[i])
        {
            ret.push_back(sortedTree[i]);
            ret.push_back(tree[i]);
            break;
        }
    }
    
    return ret;
    
}