
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

    void preorder(TreeNode* root1, vector<int>& v){
        if(root1 == NULL)
            return;
       
        preorder(root1->left, v);
        preorder(root1->right, v);
        v.push_back(root1->val);
        return;
    }
    
     vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
    

 