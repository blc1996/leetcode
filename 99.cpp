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
    void recoverTree(TreeNode* root) {
        while(!helper(root, NULL, NULL));
    }

    bool helper(TreeNode* subnode, TreeNode* maxNode, TreeNode* minNode){
        if(subnode == NULL)
            return true;
        if(maxNode && subnode->val > maxNode->val){
            int temp = maxNode->val;
            maxNode->val = subnode->val;
            subnode->val = temp;
            return false;
        }
        if(minNode && subnode->val < minNode->val){
            int temp = minNode->val;
            minNode->val = subnode->val;
            subnode->val = temp;
            return false;
        }

        if(helper(subnode->left, subnode, minNode)){
            if(!helper(subnode->right, maxNode, subnode))
                return false;
        }
        else
            return false;
        return true;
    }
};
