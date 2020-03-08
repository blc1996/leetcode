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
    unordered_map<int, int> mp;

    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(!root){
            return vector<int>();
        }
        postOrder(root);
        int curMax = 0;
        vector<int> res;
        for(auto it = mp.begin(); it != mp.end(); it++){
            // cout<<it->first<<" "<<it->second<<endl;
            if(it->second > curMax){
                curMax = it->second;
                res.clear();
                res.push_back(it->first);
            }else if(it->second == curMax){
                res.push_back(it->first);
            }
        }
        return res;
    }

    int postOrder(TreeNode* node){
        if(!node){
            return 0;
        }
        int sum = node->val + postOrder(node->left) + postOrder(node->right);
        mp[sum]++;
        return sum;
    }
};