/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorder(root, result);
        return result;
    }

    void preorder(TreeNode* subNode, vector<int>& result){
        if(subNode == NULL)
            return;

        result.push_back(subNode->val);
        preorder(subNode->left, result);
        preorder(subNode->right, result);
    }
};//recursive

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* temp = st.top();
            st.pop();
            if(temp == NULL)
                continue;

            result.push_back(temp->val);

            st.push(temp->right);
            st.push(temp->left);
        }
        return result;
    }
};//iterative
