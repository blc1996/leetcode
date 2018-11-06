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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        queue<TreeNode *> leftQ, rightQ;
        TreeNode *nodeLeft, *nodeRight;
        leftQ.push(root);
        rightQ.push(root);
        while(!leftQ.empty() && !rightQ.empty()){
            nodeLeft = leftQ.front();
            leftQ.pop();
            nodeRight = rightQ.front();
            rightQ.pop();
            if(nodeLeft->val != nodeRight->val)
                return false;

            if(nodeLeft->left != NULL){
                if(nodeRight->right == NULL)
                    return false;
                leftQ.push(nodeLeft->left);
            }

            if(nodeLeft->right != NULL){
                if(nodeRight->left == NULL)
                    return false;
                leftQ.push(nodeLeft->right);
            }

            if(nodeRight->right != NULL){
                if(nodeLeft->left == NULL)
                    return false;
                rightQ.push(nodeRight->right);
            }

            if(nodeRight->left != NULL){
                if(nodeLeft->right == NULL)
                    return false;
                rightQ.push(nodeRight->left);
            }
        }

        if(!leftQ.empty() || !rightQ.empty())
            return false;
        return true;
    }
};
