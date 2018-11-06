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
    int maxDepth(TreeNode* root) {
        queue<pair<TreeNode *, int>> q;
        if(!root)
            return 0;
        int level;
        q.push(pair<TreeNode *, int>(root, 1));
        while(!q.empty()){
            TreeNode *currentNode = q.front().first;
            level = q.front().second;
            q.pop();

            if(currentNode->left)
                q.push(pair<TreeNode *, int>(currentNode->left, level + 1));
            if(currentNode->right)
                q.push(pair<TreeNode *, int>(currentNode->right, level + 1));
        }
        return level;
    }
};
