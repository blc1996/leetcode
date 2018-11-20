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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<pair<TreeNode *, vector<int> *>> st;
        st.push(pair<TreeNode *, vector<int> *>(root, new vector<int>()));
        while(!st.empty()){
            TreeNode* node1 = st.top().first;
            vector<int>* temp = st.top().second;
            st.pop();
            if(node1 == NULL){
                result.insert(result.begin(), temp->begin(), temp->end());
                delete temp;
                continue;
            }

            temp->insert(temp->begin(), node1->val);
            st.push(pair<TreeNode *, vector<int> *>(node1->left, new vector<int>()));
            st.push(pair<TreeNode *, vector<int> *>(node1->right, temp));
        }
        return result;
    }
};
