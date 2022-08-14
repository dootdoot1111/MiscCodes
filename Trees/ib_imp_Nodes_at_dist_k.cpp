#include<bits/stdc++.h>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
    //a map of TreeNode pointers which stores the child and its parent; creating the hashmap using bfs
    void markParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent_track,TreeNode* target){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            if(current->left){
                parent_track[current->left]=current;
                q.push(current->left);
            }
            if(current->right){
                parent_track[current->right]=current;
                q.push(current->right);
            }
        }
        
    }
//finding the TreeNode pointer of the value we need to find
TreeNode* find(TreeNode* node, int key)
{
    if (node == NULL)
        return NULL;
 
    if (node->val == key)
        return node;;
 
    /* then recur on left subtree */
    TreeNode* res1 = find(node->left, key);
    // node found, no need to look further
    if(res1!=NULL) return res1;
 
    /* node is not found in left,
    so recur on right subtree */
    TreeNode* res2 = find(node->right, key);
 
    return res2;
}
  

  vector<int> distanceK(TreeNode* A, int B, int C) {
    unordered_map<TreeNode*, TreeNode*> parent_track;
    TreeNode* target=find(A,B);
    markParents(A,parent_track,target);

    unordered_map<TreeNode*,bool> visited;      //a map which will contain the treenodes that we have visited
    queue<TreeNode*> q;
    q.push(target);
    visited[target]=true;
    int curr_level=0;
    while(!q.empty()){
        int size=q.size();
        if(curr_level++ == C ) break;          //keep on doing this unless distance becomes C
        for(int i=0;i<size;i++){
                TreeNode* current =q.front();
                q.pop();
                if(current->left && !visited[current->left]){  
                    q.push(current->left);
                    visited[current->left] =true;
                }
                if(current->right && !visited[current->right]) {
                    q.push(current->right);
                    visited[current->right] = true;
                }
                if(parent_track[current] && !visited[parent_track[current]]) {
                    q.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }

        }
    }

    vector<int> ans;
    while(!q.empty()){
        TreeNode* current=q.front();
        q.pop();
        ans.push_back(current->val);
    }
    return ans;

}
