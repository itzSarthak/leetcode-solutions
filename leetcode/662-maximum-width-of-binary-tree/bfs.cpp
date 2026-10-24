class Solution {
public:
    int widthOfBinaryTree(TreeNode* root)
    {
        int ans = 0;
        if(root == NULL) return ans;

        queue<pair<TreeNode*,int>> q;
        q.push({root,0});

        while(!q.empty())
        {
            int size = q.size();
            int first,last;
            int mini = q.front().second;
            // mini helps avoid integer overflow
            
            for(int i = 0; i < size; i++)
            {
                TreeNode *currNode = q.front().first;
                long long curridx = q.front().second - mini;
                q.pop();

                if(i == 0) first = curridx;
                if(i == size - 1) last = curridx;

                if(currNode->left)  q.push({currNode->left,curridx*2 + 1});
                if(currNode->right)  q.push({currNode->right,curridx*2 + 2});
            }
            ans = max(ans,last - first + 1);
        }

        return ans;
    }
};