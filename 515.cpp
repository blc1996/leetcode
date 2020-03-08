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
    vector<int> largestValues(TreeNode* root) {
        if(!root){
            return vector<int>();
        }
        queue<TreeNode*> q;
        int maxVal = root->val;
        vector<int> res;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(!temp){
                res.push_back(maxVal);
                maxVal = INT_MIN;
                if(!q.empty()) q.push(NULL);
            }else if(temp){
                maxVal = max(maxVal, temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return res;
    }
};