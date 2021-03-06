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
    void flatten(TreeNode* root) {
        if(root == NULL)
            return;

        if(root->left != NULL){
            TreeNode* temp = root->right;
            root->right = root->left;
            root->left = NULL;
            root = root->right;
            TreeNode* currentNode = root;
            while(currentNode->right != NULL)
                currentNode = currentNode->right;
            currentNode->right = temp;
        }else{
            root = root->right;
        }
        flatten(root);
    }
};
