
class Solution {
public:
    int maxi = 0;
    int maxHeight(TreeNode* root,int& diam)
    {
        if(root == NULL) return 0;

        int lh = maxHeight(root->left,diam);
        int rh = maxHeight(root->right,diam);

        diam = max(diam,lh + rh);

        return 1 + max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root)
    {
        if(root == NULL) return 0;

        int diameter = 0;
        maxHeight(root,diameter);

        return diameter;
    }
};