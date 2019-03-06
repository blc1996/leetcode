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
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root, false);
    }
    
    int helper(TreeNode* node, bool flag){
        if(node == NULL){
            return 0;
        }
        if(node->left == NULL && node->right == NULL){
            return flag ? node->val : 0;
        } 
        return helper(node->left, true) + helper(node->right, false);
    }
};