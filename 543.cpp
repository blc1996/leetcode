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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        diameterOfBinaryTreeCore(root, res);
        return res;
    }

    int diameterOfBinaryTreeCore(TreeNode* node, int& res){
        if(!node) return 0;
        int leftHeight = 1 + diameterOfBinaryTreeCore(node->left, res);
        int rightHeight = 1 + diameterOfBinaryTreeCore(node->right, res);
        res = max(res, leftHeight + rightHeight - 2);
        return max(leftHeight, rightHeight);
    }
};