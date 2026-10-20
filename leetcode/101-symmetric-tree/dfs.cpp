class Solution {
public:
    bool solve(TreeNode* left,TreeNode *right)
    {
        if(left == NULL or right == NULL)
            return (left == right);

        if(left->val != right->val) return false;
        return solve(left->right,right->left) && solve(left->left,right->right);
    }
    bool isSymmetric(TreeNode* root)
    {
        if(root == NULL) return true;
        return solve(root->left,root->right);
    }
};