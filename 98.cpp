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
    bool isValidBST(TreeNode* root) {
        return helper(root, INT_MAX, INT_MIN)
    }

    bool helper(TreeNode *subNode, int maxVal,int minVal){
        if(subNode == NULL){
            return true;
        }

        if(subNode->val >= maxVal || subNode->val <= minVal)
            return false;

        if(!helper(subNode->left, min(maxVal, subNode->val), minVal))
            return false;

        return helper(subNode->right, maxVal, max(minVal, subNode->val));
    }
};
