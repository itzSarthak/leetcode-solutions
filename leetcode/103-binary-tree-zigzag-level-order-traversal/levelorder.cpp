
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        bool l2r = true;
        queue<TreeNode* >q;
        q.push(root);


        while(!q.empty())
        {
            int sz = q.size();
            vector<int> zz(sz);

            for(int i = 0; i < sz; i++)
            {
                TreeNode* currNode = q.front();
                q.pop();

                int idx = (l2r) ? i : (sz - i - 1);
                zz[idx] = currNode->val;


                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
            }

            l2r = !l2r;
            ans.push_back(zz);
        }

        return ans;
    }
};