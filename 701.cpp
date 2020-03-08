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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        insertIntoBSTCore(root, val);
        return root;
    }

    void insertIntoBSTCore(TreeNode*& node, int val){
        if(node == NULL){
            node = new TreeNode(val);
            return;
        }
        if(val < node->val){
            insertIntoBSTCore(node->left, val);
        }else{
            insertIntoBSTCore(node->right, val);
        }
    }
};