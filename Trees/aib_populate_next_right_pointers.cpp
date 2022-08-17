#include <bits/stdc++.h>
using namespace std;

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode* A) {
    
    if(!A)
        return;
    
    queue<TreeLinkNode*> q;
    
    q.push(A);
    int len;
    
    while(!q.empty())
    {   
        len = q.size();
        
        for(int i = 0; i < len; i++)
        {
            TreeLinkNode* curr = q.front();
            q.pop();
            
            if(i == len-1)
            {
                curr->next = NULL;
            }
            
            else
            {
                curr->next = q.front();
            }
            
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
    
}
