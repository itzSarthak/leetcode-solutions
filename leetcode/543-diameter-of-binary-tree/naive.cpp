
class Solution {
public:
    int maxi = 0;
    int maxHeight(TreeNode* root)
    {
        if(root == NULL) return 0;

        return 1 + max(maxHeight(root->left),maxHeight(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root)
    {
        if(root == NULL) return 0;

        int lh = maxHeight(root->left);
        int rh = maxHeight(root->right);

        maxi = max(maxi,lh + rh);

        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);

        return maxi;
        
    }
};