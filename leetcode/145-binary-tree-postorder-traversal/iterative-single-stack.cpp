
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int>postorder;
        TreeNode* currNode = root;
        stack<TreeNode* >st;

        while(currNode || !st.empty())
        {
            if(currNode)
            {
                st.push(currNode);
                currNode = currNode->left;
            }
            else
            {
                TreeNode* temp = st.top()->right;
                if(temp)
                    currNode = temp;

                else
                {
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->val);

                    while(!st.empty() && temp == st.top()->right)
                    {
                        temp = st.top();
                        st.pop();
                        postorder.push_back(temp->val);
                    }
                }
            }
        }
        return postorder;
    }
};