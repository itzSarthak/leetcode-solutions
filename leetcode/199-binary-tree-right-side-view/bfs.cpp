class Solution {
public:
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> res;
        if(root == NULL) return res;

        queue<pair<TreeNode*, int>> q;
        map<int, int> mp;

        q.push({root, 0});

        while(!q.empty())
        {
            auto idx = q.front();
            q.pop();

            TreeNode* currNode = idx.first;
            int level = idx.second;

            mp[level] = currNode->val;

            if(currNode->left) q.push({currNode->left, level + 1});
            if(currNode->right) q.push({currNode->right, level + 1});
        }

        for(auto it : mp)
            res.push_back(it.second);

        return res;
    }
};