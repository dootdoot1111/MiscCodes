TreeNode* remove(TreeNode* root)
{
    // agar passed node hi null hai toh return null
    if(!root)
    {
        return NULL;
    }
    
    root->left = remove(root->left);
    root->right = remove(root->right);

    // pehle hi remove chaalu kar do left aur right pe, taaki jab left right ke baccho ko check karo toh tho final ho
    
    if(!root->right && !root->left)
    {
        return root;
    }

    // dono bacche null hai toh kuch mat karo
    
    if(!root->right)
    {
        return root->left;
    }

    // right baccha null hai toh left baccha return and vice versa
    
    if(!root->left)
    {
        return root->right;
    }
    
    return root;

    //agar dono hi bacche hai toh bhi kuch mat karo
} 

TreeNode* Solution::solve(TreeNode* A) {
    
    return remove(A);
}