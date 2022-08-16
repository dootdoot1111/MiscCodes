#include<bits/stdc++.h>
using namespace std;
//   Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
//updating the Tree A according to the question parameters, toh agar B NULL hai toh simply return, warna check karo ki if left and right child exists, and return according.
void helper(TreeNode* A,TreeNode*B){
    if (B==NULL )
    return;
    
    if(A&&B){
    A->val=A->val+B->val;}
    
    if(!A->left && B->left){
        A->left = B->left;
        B->left = NULL;
    }
    if(!A->right && B->right){
        A->right = B->right;
        B->right = NULL;
    }
    helper(A->left, B->left);
    helper(A->right, B->right);
}
TreeNode* solve(TreeNode* A, TreeNode* B) {
 helper(A,B);
 return A;
    
}
