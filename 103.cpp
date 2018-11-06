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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<pair<TreeNode *, int>> q;
        vector<vector<int>> result;
        vector<int> temp;
        if(!root)
            return result;
        q.push(pair<TreeNode *, int>(root, 1));
        helper(q, result, temp);
        return result;
    }

    void helper(queue<pair<TreeNode *, int>> &q, vector<vector<int>>& result, vector<int>& temp){
        if(q.empty()){
            result.push_back(temp);
            return;
        }

        TreeNode *currentNode = q.front().first;
        int level = q.front().second;
        q.pop();
        if(level > result.size() + 1){
            result.push_back(temp);
            temp.clear();
        }

        if(level % 2 == 1)
            temp.push_back(currentNode->val);
        else
            temp.insert(temp.begin(), currentNode->val);

        if(currentNode->left)
            q.push(pair<TreeNode *, int>(currentNode->left, level + 1));
        if(currentNode->right)
            q.push(pair<TreeNode *, int>(currentNode->right, level + 1));

        helper(q, result, temp);
    }
};

//iterative!
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<pair<TreeNode *, int>> q;
        vector<vector<int>> result;
        vector<int> temp;
        if(!root)
            return result;
        q.push(pair<TreeNode *, int>(root, 1));
        while(!q.empty()){
            TreeNode *currentNode = q.front().first;
        int level = q.front().second;
        q.pop();
        if(level > result.size() + 1){
            result.push_back(temp);
            temp.clear();
        }

        if(level % 2 == 1)
            temp.push_back(currentNode->val);
        else
            temp.insert(temp.begin(), currentNode->val);

        if(currentNode->left)
            q.push(pair<TreeNode *, int>(currentNode->left, level + 1));
        if(currentNode->right)
            q.push(pair<TreeNode *, int>(currentNode->right, level + 1));
        }
        result.push_back(temp);
        return result;
    }

};
