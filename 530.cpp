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
    int getMinimumDifference(TreeNode* root) {
        int minDif = INT_MAX;
        getMinimumDifferenceCore(root, minDif);
        return minDif;
    }

    pair<int, int> getMinimumDifferenceCore(TreeNode* node, int& minDif){
        int minMax = node->val, maxMin = node->val, minMin = node->val, maxMax = node->val;
        if(node->left){
            auto temp = getMinimumDifferenceCore(node->left, minDif);
            minMax = temp.second;
            minMin = temp.first;
        }
        if(node->right){
            auto temp = getMinimumDifferenceCore(node->right, minDif);
            maxMax = temp.second;
            maxMin = temp.first;
        }
        int tempMin = min(node->val - minMax == 0 ? INT_MAX: node->val - minMax, maxMin - node->val == 0 ? INT_MAX:  maxMin - node->val);
        minDif = min(minDif, tempMin);
        return pair<int, int>(minMin, maxMax);
    }
};