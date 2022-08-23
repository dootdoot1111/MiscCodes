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


  //2 ways- 1)using 2 stacks; 2) using a deque

    //simple level order but using two stacks to reverse the level
 vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    vector<int> arr;
    vector<int> n;   //for initialising a new array 
    stack<TreeNode*> currentLevel;
    stack<TreeNode*> nextLevel;

    currentLevel.push(root);

    bool lefttoright=true;
    if (root==NULL){
            return ans;
    }
        while(!currentLevel.empty()) {
            
            TreeNode* temp=currentLevel.top();
            currentLevel.pop();

            if(temp!=NULL){
                arr.push_back(temp->val);

                if (lefttoright) {
                if (temp->left)
                    nextLevel.push(temp->left);
                if (temp->right)
                    nextLevel.push(temp->right);
            }
            else {
                if (temp->right)
                    nextLevel.push(temp->right);
                if (temp->left)
                    nextLevel.push(temp->left);
            }
            }

            
            if (currentLevel.empty()) {
            ans.push_back(arr);
            arr=n;
            lefttoright = !lefttoright;
            swap(currentLevel, nextLevel);
        }

        }
        return ans;
        
    }



