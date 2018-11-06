/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//recursive
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> output;
        helper(root, output);
        return output;
    }

    void helper(TreeNode* subNode, vector<int>& result){
        if(subNode == NULL)
            return;

        helper(subNode->left, result);
        result.push_back(subNode->val);
        helper(subNode->right, result);
    }
};


//iterative
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> output;
        stack<TreeNode *> leftStack;
        if(root == NULL){
            return output;
        }
        TreeNode *currentNode = root;
        int flag = 0;
        leftStack.push(root);
        while(!leftStack.empty()){
            if(flag == 0){
                if(currentNode->left != NULL){
                    currentNode = currentNode->left;
                    leftStack.push(currentNode);
                    continue;
                }else{
                    currentNode = leftStack.top();
                    output.push_back(currentNode->val);
                    leftStack.pop();
                    if(currentNode->right != NULL){
                        currentNode = currentNode->right;
                        leftStack.push(currentNode);
                    }else{
                        flag = 1;
                    }
                }
            }else{
                currentNode = leftStack.top();
                leftStack.pop();
                output.push_back(currentNode->val);
                if(currentNode->right != NULL){
                    currentNode = currentNode->right;
                    leftStack.push(currentNode);
                    flag = 0;
                    continue;
                }
            }
        }
        return output;
    }
};
