#include<bits/stdc++.h>
using namespace std;
//   Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
//reverse karna ho toh stack best
vector<int> solve(TreeNode* A) {
    stack<TreeNode*> s;
    queue<TreeNode*> q;
    vector<int> v;
    q.push(A);
    while(!q.empty()){
        TreeNode* temp=q.front();
        s.push(temp);
        q.pop();
        
        
        if(temp->right)
        q.push(temp->right);
        if(temp->left)
        q.push(temp->left);
    }
    while(!s.empty()){
        TreeNode* temp2;
        temp2=s.top();
        v.push_back(temp2->val);
        s.pop();
    }
    return v;
}