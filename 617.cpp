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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL && t2 == NULL)
            return NULL;
        TreeNode* cur = new TreeNode(0);
        if(t1 && t2){
            cur->val = t1->val + t2->val;
            cur->left = mergeTrees(t1->left, t2->left);
            cur->right = mergeTrees(t1->right, t2->right);
        }else if(t1){
            cur->val = t1->val;
            cur->left = mergeTrees(t1->left, NULL);
            cur->right = mergeTrees(t1->right, NULL);
        }else if(t2){
            cur->val = t2->val;
            cur->left = mergeTrees(NULL, t2->left);
            cur->right = mergeTrees(NULL, t2->right);
        }
        return cur;
    }
};
