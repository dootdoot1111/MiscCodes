#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<int> solve(TreeNode* A, int B) {
    
    if(A->val == B)
    {
        return {};
    }
    
    queue<TreeNode*> q;
    q.push(A);
    int len;
    
    while(!q.empty())
    {
        len=q.size();
        bool flag = false;
        vector<int> v;
        
        for(int i=0;i<len;i++){
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp->left && temp->left->val == B || temp->right && temp->right->val == B)
            {
                flag = true;
            }

            else 
            {
                if(temp->left) 
                {
                    q.push(temp->left);
                    v.push_back(temp->left->val);
                }
                if(temp->right) 
                {
                    q.push(temp->right);
                    v.push_back(temp->right->val);
                }
            }
        }
        
        if(flag)
            return v;
    }
    
}
