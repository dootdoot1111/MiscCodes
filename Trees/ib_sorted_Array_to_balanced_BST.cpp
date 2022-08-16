#include<bits/stdc++.h>
using namespace std;
//   Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
 //sorted array ka mid will be the node, and phir left child will start se mid-1 ka mid value, right child will be mid+1 se end tak ka mid value 
 TreeNode* helper(const vector<int> &A,int start,int end){
    if(start>end)
    return NULL;
    int mid=(start+end)/2;
    TreeNode* root=new TreeNode(A[mid]);    //creating a node
         root->left=helper(A,start,mid-1);
        root->right=helper(A,mid+1,end);
        return root;
}
TreeNode* sortedArrayToBST(const vector<int> &A) {
    int start=0;
    int end=A.size()-1;
    return helper(A,start,end);
}
