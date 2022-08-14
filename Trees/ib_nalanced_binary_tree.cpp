#include<bits/stdc++.h>
using namespace std;

//maintain a height function jo har ek node ke depth ko check karegaand return hte answer accordingly
//   Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
 int depth(TreeNode *node){
    if(node==NULL)
    return 0;

    return max(depth(node->left),depth(node->right))+1;
}


int isBalanced(TreeNode* A) {
    if(A==NULL) return 1;

if(abs(depth(A->left)-depth(A->right))>1){
return 0;
}
 if(isBalanced(A->left)&&isBalanced(A->right)){
            return(1);
        }
        return(0);
}