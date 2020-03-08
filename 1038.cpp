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
    TreeNode* bstToGst(TreeNode* root) {
        if(!root) return root;
        int tempInt = 0;
        bstToGstCore(root, tempInt);
        return root;
    }

    void bstToGstCore(TreeNode* node, int& nodeVal){
        if(!node) return;
        bstToGstCore(node->right, nodeVal);
        nodeVal += node->val;
        node->val = nodeVal;
        bstToGstCore(node->left, nodeVal);
    }
};