 #include<bits/stdc++.h>
 using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 


//simple inorder; heap bhi use kar sakte hain

void helper(TreeNode* A,vector<int> &inorder){
    if(A==NULL)
    return;
    
   
    helper(A->left,inorder);
    inorder.push_back(A->val);
    helper(A->right,inorder);
}
int kthsmallest(TreeNode* A, int B) {
    vector<int> inorder;
    helper(A,inorder);
    
    return inorder[B-1];
}
