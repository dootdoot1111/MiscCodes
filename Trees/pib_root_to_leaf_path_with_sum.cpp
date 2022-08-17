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
 

//good ques
bool f(TreeNode* root, int currsum, int sum, vector<vector<int>> &ans, vector<int> &tempAns){

    if(root->left == NULL and root->right == NULL){                 //if we are at the leaf node
        currsum += root->val;
        tempAns.push_back(root->val);

        if(currsum == sum){                                         //if the sum matches the given sum
            ans.push_back(tempAns);                          
            tempAns.pop_back();
            return true;
        }
        tempAns.pop_back();                                          //if it doesnt match the given sum
        return false;                   
    }

    tempAns.push_back(root->val);                                      //keep adding the nodes to the vector as we traverse
    bool left = 0, right = 0;

    if(root->left != NULL){
        left = f(root->left, currsum + root->val, sum, ans, tempAns);       //keep incrementing the temp sum with the value of the node thats been added:left tree pe
    }
    if(root->right != NULL){
        right = f(root->right, currsum + root->val, sum, ans, tempAns);     //keep incrementing the temp sum with the value of the node thats been added:right tree pe
    }
    tempAns.pop_back();
   
    return left or right;   //this step, is somewhat like backtracking, returning back to the parent function

}

vector<vector<int> > pathSum(TreeNode* root, int sum) {

    vector<vector<int>> ans;
    vector<int> tempAns;

    f(root, 0, sum, ans, tempAns);
    return ans;

}