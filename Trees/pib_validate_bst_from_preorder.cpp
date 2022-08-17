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
 

int solve(vector<int> &preorder) {
    stack<int> st;
    
    set<int> t;         //to check for duplicate elements
    for(int i=0;i<preorder.size();i++){
        t.insert(preorder[i]);
    }
    if(t.size()!=preorder.size())
    return 0;
    
    int root = INT_MIN;            //using stack to check the preorder
    for (int i=0; i < preorder.size(); i++)
    {
        while (!st.empty() && preorder[i] > st.top())
        {
            root = st.top();
            st.pop();
        }
        if (preorder[i] < root)
            return 0;
        st.push(preorder[i]);
    }
    return 1;
}
