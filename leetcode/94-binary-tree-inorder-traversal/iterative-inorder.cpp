/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> inorder;
        if(root == NULL) return inorder;
        TreeNode* currNode = root;
        stack<TreeNode*>st;


        while(true)
        {
            if(currNode)
            {
                st.push(currNode);
                currNode = currNode->left;
            }
            else
            {
                if(st.empty()) break;

                currNode = st.top();
                inorder.push_back(currNode->val);
                st.pop();
                currNode = currNode->right;
            }
        }

        return inorder;
    }
};