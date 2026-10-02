
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int>postorder;
        if(root == NULL) return postorder;
        TreeNode* currNode;

        stack<TreeNode*> st1,st2;
        st1.push(root);

        while(!st1.empty())
        {
            currNode = st1.top();
            st1.pop();
            st2.push(currNode);

            if(currNode->left) st1.push(currNode->left);
            if(currNode->right) st1.push(currNode->right);
        }

        while(!st2.empty())
        {
            postorder.push_back(st2.top()->val);
            st2.pop();
        }
        return postorder;
    }
};