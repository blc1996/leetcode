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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root == NULL)
            return result;
        helper(root, 1, result);
        return result;
    }

    void helper(TreeNode* subnode, int height, vector<int>& result){
        if(height > result.size())
            result.push_back(subnode->val);
        if(subnode->right){
            helper(subnode->right, height + 1, result);
        }
        if(subnode->left){
            helper(subnode->left, height + 1, result);
        }
    }
};
