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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return root;
        }
        TreeNode* initialNode = new TreeNode(INT_MAX);
        initialNode->left = root;
        TreeNode*& targetNode = findNode(initialNode, key);
        if(!targetNode){
            return root;
        }else if(targetNode->left == NULL && targetNode->right == NULL){
            targetNode = NULL;
        }else if(targetNode->left == NULL){
            targetNode = targetNode->right;
        }else if(targetNode->right == NULL){
            targetNode = targetNode->left;
        }else{
            if(targetNode->right->left == NULL){
                targetNode->val = targetNode->right->val;
                targetNode->right = targetNode->right->right;
            }else{
                TreeNode* tempNode = targetNode->right->left;
                TreeNode* parent = targetNode->right;
                while(tempNode->left){
                    tempNode = tempNode->left;
                    parent = parent->left;
                }
                targetNode->val = tempNode->val;
                parent->left = tempNode->right;
            }
        }
        return initialNode->left;
    }

    TreeNode*& findNode(TreeNode* node, int key){
        if(node->left && node->left->val == key){
            return node->left;
        }else if(node->right && node->right->val == key){
            return node->right;
        }

        if(node->val < key){
            if(node->right)
                return findNode(node->right, key);
            else
                return node->right;
        }else{
            if(node->left)
                return findNode(node->left, key);
            else
                return node->left;
        }
    }
};