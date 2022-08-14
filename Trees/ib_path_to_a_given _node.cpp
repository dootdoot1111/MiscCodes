
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
 

//bc vector mein back() function bhi hota hai
void dfs2(TreeNode*A,int key,vector<int>&ans)
     {
         if(!A)return;
         ans.push_back(A->val);
         dfs2(A->left,key,ans);
         if(ans.back()==key)return;
         dfs2(A->right,key,ans);
         if(ans.back()==key)return;
         ans.pop_back();
         return;
     }
     
    vector<int> solve(TreeNode* A, int B) {
        vector<int>ans;
        dfs(A,B,ans);
        return ans;
    }

//2
bool dfs(TreeNode* root,int x,vector<int>&ans)
     {
         if(!root) return false;
         ans.push_back(root->val);
        if(root->val==x)
        return true;
        
        if(dfs(root->left,x,ans) || dfs(root->right,x,ans) )
        return true;
        
        ans.pop_back();
        return false;
     }
     
    vector<int> solve(TreeNode* A, int B) {
        vector<int>ans;
        if(A==NULL){
            return ans;
        }
        dfs(A,B,ans);
        return ans;
    }