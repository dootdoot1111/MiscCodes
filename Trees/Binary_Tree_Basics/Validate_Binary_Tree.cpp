/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    
    void helper(TreeNode* root, vector<int> &nodes){
        if(root == NULL)
            return;
        helper(root->left, nodes);
        nodes.push_back(root->val);
        helper(root->right, nodes);
        return;
        
    }
    bool isValidBST(TreeNode* root) {
        vector<int> nodes;
        
        helper(root,nodes);
        
        unordered_set<int> s;
        for(int i=0;i<nodes.size();i++){
            s.insert(nodes[i]);
        }
        if(s.size()!=nodes.size()){
            return false;
        }
        return is_sorted(nodes.begin(),nodes.end());
        
    }
};