class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        queue<TreeNode* > q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            vector<int> level;

            for(int i = 0; i < size; i++)
            {
                TreeNode *currNode = q.front();
                q.pop();
                level.push_back(currNode->val);

                if(currNode->left != NULL) q.push(currNode->left);
                if(currNode->right != NULL) q.push(currNode->right);
            }

            ans.push_back(level);
        }

        return ans;
    }
};