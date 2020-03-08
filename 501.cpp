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
    vector<int> findMode(TreeNode* root) {
        if(!root){
            return vector<int>();
        }
        int maxCount = 0, curCount = 0, prev = root->val + 1;
        vector<int> res;
        stack<TreeNode *> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* curNode = st.top();
            st.pop();
            if(curNode->right) st.push(curNode->right);
            if(curNode->left) st.push(curNode->left);
            if(curNode->val == prev){
                curCount++;
            }else{
                prev = curNode->val;
                curCount = 1;
            }
            if(curCount > maxCount){
                res.clear();
                res.push_back(prev);
            }else if(curCount == maxCount){
                res.push_back(prev);
            }
        }
        return res;
    }
};


class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        if(!root){
            return vector<int>();
        }
        vector<int> res;
        unordered_map<int, int> mp;
        stack<TreeNode *> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* curNode = st.top();
            st.pop();
            if(curNode->right) st.push(curNode->right);
            if(curNode->left) st.push(curNode->left);
            mp[curNode->val]++;
        }
        int curMax = 0;
        for(auto it = mp.begin(); it != mp.end(); it++){
            if(it->second > curMax){
                res.clear();
                curMax = it->second;
                res.push_back(it->first);
            }else if(it->second == curMax){
                res.push_back(it->first);
            }
        }

        return res;
    }
};