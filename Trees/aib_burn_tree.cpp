#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* markParents(TreeNode* A, int B, map<TreeNode*, TreeNode*> &parent)
{
    queue<TreeNode*> q;
    TreeNode* target;
    q.push(A);
    
    int len;
    
    while(!q.empty())
    {
        len = q.size();
        
        for(int i = 0; i < len; i++)
        {
            TreeNode* curr = q.front();
            q.pop();
            
            if(curr->val == B)
            {
                target = curr;
            }
            
            if(curr->left)
            {
                q.push(curr->left);
                parent[curr->left] = curr;
            }
            
            if(curr->right)
            {
                q.push(curr->right);
                parent[curr->right] = curr;
            }
        }
    }
    
    return target;
}

int burnTree(TreeNode* root, map<TreeNode*, TreeNode*> &parent, map<TreeNode*, bool> &visited)
{
    queue<TreeNode*> q;
    
    q.push(root);
    visited[root] = true;
    int len, time = 0;
    
    while(!q.empty())
    {
        len = q.size();
        int burned = 0;
        
        for(int i = 0; i < len; i++)
        {
            TreeNode* curr = q.front();
            q.pop();
            
            if(parent[curr] && !visited[parent[curr]])
            {
                visited[parent[curr]] = true;
                q.push(parent[curr]);
                burned++;
            }
            
            if(curr->left && !visited[curr->left])
            {
                visited[curr->left] = true;
                q.push(curr->left);
                burned++;
            }
            
            if(curr->right && !visited[curr->right])
            {
                visited[curr->right] = true;
                q.push(curr->right);
                burned++;
            }
        }
        
        if(burned > 0)
        {
            time++;
        }
    }
    
    return time;
}

int solve(TreeNode* A, int B) {
    
    map<TreeNode*, TreeNode*> parent;
    map<TreeNode*, bool> visited;
    int time;
    
    TreeNode* target = markParents(A, B, parent);
    
    time = burnTree(target, parent, visited);
    
    return time;
    
}