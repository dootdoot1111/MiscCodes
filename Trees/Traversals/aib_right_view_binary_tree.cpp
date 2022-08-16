#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
void helper(TreeNode* root, vector<int> &arr)
{
    queue<TreeNode*> q;
    q.push(root);
    
    int len;
    
    while(!q.empty())
    {
        len = q.size();
        for(int i = 0; i < len; i++)
        {
            TreeNode* curr = q.front();
            
            if(i == len-1)
                arr.push_back(curr->val);
            
            if(curr->left)
                q.push(curr->left);
                
            if(curr->right)
                q.push(curr->right);  
                 
            q.pop();
        }
    }
    
}

vector<int> solve(TreeNode* A) {
    vector<int> ret;
    helper(A, ret);
    
    return ret;
    
}