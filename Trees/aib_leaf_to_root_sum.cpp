#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    
    void helper(TreeNode* root, int number, int &sum)
    {
        if(!root)
        {
            return;
        }

        if(!root->left && !root->right)
        {
            sum += number;
        }

        if(root->left)
        {
            helper(root->left, 10*number + root->left->val, sum);
        }

        if(root->right)
        {
            helper(root->right, 10*number + root->right->val, sum);
        }

    }
    
    int sumNumbers(TreeNode* root) {
        int ret = 0;
        helper(root, root->val, ret);
        return ret;
    }
};