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
 

//ek approach- inorder karke saare elements mein phir two pointer se search karlo, warna O(n) mein karne ke liye, given sum se minus karke dekho agar number present hai toh return 1, warna push that element into the set
int t2Sum(TreeNode* A, int B) {
    unordered_set<int> s;
    queue<TreeNode*> q;
    q.push(A);
    while(!q.empty()){
        TreeNode* curr=q.front();
        q.pop();
        if(s.find(B-curr->val)!=s.end())
        return 1;
        s.insert(curr->val);
        
        if(curr->right!=NULL)
        q.push(curr->right);
        if(curr->left!=NULL)
        q.push(curr->left);
    } 
    return 0;
    
    
}
