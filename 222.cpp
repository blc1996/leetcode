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
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;

        int height = sameHeight(root);
        if(height > 0){
            return countNodes(root->right) + pow(2, height);
        }else{
            return countNodes(root->right) + countNodes(root->left) + 1;
        }
    }

    int sameHeight(TreeNode* node){
        TreeNode* leftTree = node->left;
        TreeNode* rightTree = node->right;
        int count = 0;
        while(leftTree != NULL && rightTree != NULL){
            leftTree = leftTree->left;
            rightTree = rightTree->left;
            count++;
        }
        if(leftTree == NULL)
            return count;
        else
            return -count;
    }
};

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
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;

        int hl = 0, hr = 0;
        TreeNode* leftTree = root->left;
        TreeNode* rightTree = root->right;
        while(leftTree){
            leftTree = leftTree->left;
            hl++;
        }
        while(rightTree){
            rightTree = rightTree->left;
            hr++;
        }
        if(hl == hr){
            return countNodes(root->right) + pow(2, hl);
        }else{
            return countNodes(root->right) + countNodes(root->left) + 1;
        }
    }

};

