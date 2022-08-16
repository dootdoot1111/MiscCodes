#include<bits/stdc++.h>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

int func(TreeNode* root,int sum,int a){
     if(root->left==NULL && root->right==NULL){
         if(a+root->val==sum) return 1;
         else  return 0;
     }
   int s1=(root->left==NULL) ? 0:func(root->left,sum,a+root->val);
   int s2=(root->right==NULL) ? 0:func(root->right,sum,a+root->val);
   
     return (s1 || s2);
 }
int hasPathSum(TreeNode* A, int B) {
    return func(A,B,0);
}