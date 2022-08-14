#include<bits/stdc++.h>
using namespace std;

//   Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
int isSameTree(TreeNode* A, TreeNode* B) {
    if(!A&&!B)             //if both null
    return 1;
    
    if((!A&&B) || (A&&!B))  //if either one of them null
    return 0;
    
    if(A->val!=B->val)    //if their values dont match
    return 0;
    
    int l=isSameTree(A->left,B->left);     //recursivly call for left and right side 
    int r=isSameTree(A->right,B->right);
    
    if(l&&r)        //agar dono balanced hai toh gg
    return true;
    else
    return false;
}
