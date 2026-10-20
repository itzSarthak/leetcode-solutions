class Solution {
public:
    void rightViewSol(TreeNode* currNode,int level,vector<int>& res)
    {
        if(currNode == NULL) return;

        if(level == res.size()) res.push_back(currNode->val);

        rightViewSol(currNode->right,level + 1,res);
        rightViewSol(currNode->left,level + 1,res);

    }

    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> res;
        rightViewSol(root,0,res);

        return res;
    }
};