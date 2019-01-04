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
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL)
            return NULL;
        int step = k, res;
        dfs(root, step, res);
        return res;
    }

    void dfs(TreeNode* node, int& step, int& res){
        if(node == NULL){
            return;
        }
        dfs(node->left, step, res);
        step--;
        if(step == 0){
            res = node->val;
            return;
        }
        if(step > 0)
            dfs(node->right, step, res);
    }
};
