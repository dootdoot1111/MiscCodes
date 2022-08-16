#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void helper(TreeNode* root, vector<int> &arr)
{
    if(!root)
        return;
    helper(root->left, arr);
    arr.push_back(root->val);
    helper(root->right, arr);
}

int t2Sum(TreeNode* A, int B) {
    
    vector<int> treeArr;
    
    helper(A, treeArr);
    
    int i = 0, j = treeArr.size()-1;
    
    while(i < j)
    {
        if(treeArr[i] + treeArr[j] == B)
        {
            return 1;
        }
        
        else if(treeArr[i] + treeArr[j] < B)
        {
            i++;
        }
        
        else
        {
            j--;
        }
    }
    
    return 0;
    
}
