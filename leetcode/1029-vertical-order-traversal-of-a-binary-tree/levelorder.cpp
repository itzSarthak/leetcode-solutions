class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> idx;

        idx.push({root,{0,0}});
        while(!idx.empty())
        {
            auto el = idx.front();
            idx.pop();

            TreeNode* currNode = el.first;
            int x = el.second.first;
            int y = el.second.second;

            nodes[x][y].insert(currNode->val);

            if(currNode->left) idx.push({currNode->left,{x - 1,y + 1}});
            if(currNode->right) idx.push({currNode->right,{x + 1,y + 1}});
        }

        vector<vector<int>> ans;
        for(auto p : nodes)
        {
            vector<int> temp;
            for(auto q : p.second)
                temp.insert(temp.end(),q.second.begin(),q.second.end());

            ans.push_back(temp);
        }

        return ans;
        
    }
};