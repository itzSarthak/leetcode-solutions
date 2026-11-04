class Solution {
public:
    void parentmarker(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent)
    {
        queue<TreeNode* > q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* currNode = q.front();
            q.pop();
            if(currNode->left)
            {
                parent[currNode->left] = currNode;
                q.push(currNode->left);
            }
            if(currNode->right)
            {
                parent[currNode->right] = currNode;
                q.push(currNode->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
    {
        unordered_map<TreeNode*,TreeNode*>parent;
        parentmarker(root,parent);

        // every node now has -> parent left right all marked

        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode* > q;

        q.push(target);
        visited[target] = true;
        int level = 0;

        while(!q.empty())
        {
            if(level == k) break;
            level++;

            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode* currNode = q.front();
                q.pop();

                if(currNode->left && visited[currNode->left] == false)
                {
                    q.push(currNode->left);
                    visited[currNode->left] = true;
                }
                if(currNode->right && visited[currNode->right] == false)
                {
                    q.push(currNode->right);
                    visited[currNode->right] = true;  
                }
                if(parent[currNode] && visited[parent[currNode]] == false)
                {
                    q.push(parent[currNode]);
                    visited[parent[currNode]] = true;
                }
            }
        }

        // At the end the remaining element inside the q is our final answer
        vector<int> res;
        while(!q.empty())
        {
            TreeNode* currNode = q.front();
            q.pop();

            res.push_back(currNode->val);
        }

        return res;
    }
};