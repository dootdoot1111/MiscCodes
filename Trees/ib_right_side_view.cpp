#include<bits/stdc++.h>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

//right side view,maintain a counter like a level and keep incrementing it, also call right pehle
void helper(TreeNode* A,int level,vector<int> &ans){
    if(A==NULL)
    return;
    
    if(level==ans.size()){
        ans.push_back(A->val);
    }
    helper(A->right,level+1,ans);
    helper(A->left,level+1,ans);
}
vector<int> solve(TreeNode* A) {
        vector<int> ans;
      int height=0;
      helper(A,height,ans);
    return ans;
    
}
