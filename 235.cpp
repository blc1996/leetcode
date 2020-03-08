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
    TreeNode* result;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        result = NULL;
        helper(root, p, q);
        return result;
    }

    int helper(TreeNode* node, TreeNode* p, TreeNode* q){
        if(node == NULL)
            return 0;

        int temp = helper(node->left, p, q) + helper(node->right, p, q);
        if(node == p || node == q)
            temp++;

        if(temp == 2 && result == NULL)
            result = node;

        return temp;
    }
};
