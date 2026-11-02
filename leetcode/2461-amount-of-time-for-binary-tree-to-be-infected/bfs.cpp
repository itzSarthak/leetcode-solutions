
class Solution {
public:
    TreeNode* parentmarker(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent,int start)
    {
        queue<TreeNode* > q;
        q.push(root);
        TreeNode* res;

        while(!q.empty())
        {
            TreeNode* currNode = q.front();
            q.pop();

            if(currNode->val == start) res = currNode;

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

        return res;
    }
    int amountOfTime(TreeNode* root, int start)
    {
        TreeNode* startNode;
        unordered_map<TreeNode*,TreeNode*>parent;
        startNode = parentmarker(root,parent,start);

        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode* > q;

        q.push(startNode);
        visited[startNode] = true;
        int timer = 0;

        while(!q.empty())
        {
            int size = q.size();
            bool burned = false;
            for(int i = 0; i < size; i++)
            {
                TreeNode* currNode = q.front();
                q.pop();

                if(currNode->left && visited[currNode->left] == false)
                {
                    q.push(currNode->left);
                    visited[currNode->left] = true;
                    burned = true;
                }
                if(currNode->right && visited[currNode->right] == false)
                {
                    q.push(currNode->right);
                    visited[currNode->right] = true;  
                    burned = true;
                }
                if(parent[currNode] && visited[parent[currNode]] == false)
                {
                    q.push(parent[currNode]);
                    visited[parent[currNode]] = true;
                    burned = true;
                }
            }

            if(burned) timer++;
        }

        return timer;
    }
};