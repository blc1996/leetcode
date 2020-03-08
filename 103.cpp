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

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return vector<vector<int>>();
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        bool directionFlag = true;
        vector<vector<int>> res;
        vector<int> tempLevel;
        while(!q.empty()){
            TreeNode* curNode = q.top();
            q.pop();
            if(!curNode){
                res.push_back(tempLevel);
                tempLevel = !tempLevel;
                if(q.empty()){
                    break;
                }else{
                    tempLevel.clear();
                    q.push(NULL);
                }
            }
            if(directionFlag){
                tempLevel.push_back(curNode->val);
            }else{
                tempLevel.insert(tempLevel.begin(), curNode->val);
            }
            
            if(curNode->right) q.push_back(curNode->right);
            if(curNode->left) q.push_back(curNode->left);
        }
        return res;
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
