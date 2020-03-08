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
    int pathSum(TreeNode* root, int sum) {
        if(!root){
            return 0;
        }
        return pathSumCore(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

    int pathSumCore(TreeNode* root, int sum){
        if(!root){
            return 0;
        }
        int carrier = root->val == sum;
        return carrier + pathSumCore(root->left, sum - root->val) + pathSumCore(root->right, sum - root->val);
    }
};