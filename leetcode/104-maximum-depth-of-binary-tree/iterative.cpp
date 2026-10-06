
class Solution {
public:
    int maxDepth(TreeNode* root)
    {
        int ans = 0;
        if(root == NULL) return 0;

        queue<TreeNode* > q;
        q.push(root);
        

        while(!q.empty())
        {
            int size = q.size();
            ans++;
            for(int i = 0; i < size; i++)
            {
                TreeNode *currNode = q.front();
                q.pop();


                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
            }

        }

        return ans;
    }
};