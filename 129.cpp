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
    int sumNumbers(TreeNode* root) {
        if(root == NULL)
            return 0;
        int sum = 0;
        DFS(root, 0, sum);
        return sum;
    }

    void DFS(TreeNode* subNode, int temp, int& sum){
        if(subNode->left == NULL && subNode->right == NULL){
            sum += temp*10 + subNode->val;
            return;
        }

        if(subNode->left)
            DFS(subNode->left, temp*10 + subNode->val, sum);
        if(subNode->right)
            DFS(subNode->right, temp*10 + subNode->val, sum);
    }
};
