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

    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> preorder;
        if(root == NULL) return preorder;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty())
        {
            TreeNode* currNode = st.top();
            preorder.push_back(currNode->val);
            st.pop();


            if(currNode->right) st.push(currNode->right);
            if(currNode->left) st.push(currNode->left);
            // left before right so that left reaming at the top

        }

        return preorder;

    }
};