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
    int maxPathSum(TreeNode* root) {
        bool temp;
        return helper(root, &temp);
    }

    int helper(TreeNode* root, bool* connect){
        if(root == NULL)
            return 0;
        bool leftC = true, rightC = true;
        long left = helper(root->left, &leftC);
        long right = helper(root->right, &rightC);
        if(root->left == NULL)
            left = INT_MIN;
        if(root->right == NULL)
            right = INT_MIN;
        long temp = root->val;
        // cout<<temp<<" "<<left<<" "<<right;
        if(!leftC && ! rightC){
            int maxVal = max(max(left, right), temp);
            if(maxVal != temp)
                *connect = false;
            return maxVal;
        }else if(!leftC){
            int maxVal = max(max(max(left, right), temp), temp + right);
            if(temp < 0 && (maxVal == left || maxVal == right))
                *connect = false;
            return maxVal;
        }else if(!rightC){
            int maxVal = max(max(max(left, right), temp), temp + left);
            if(temp < 0 && (maxVal == left || maxVal == right))
                *connect = false;
            return maxVal;
        }
        int maxVal =  max(max(max(max(max(temp, temp + left), temp + right), right), left), temp + left + right);
        if(temp < 0 && (maxVal == left || maxVal == right))
            *connect = false;
        return maxVal;
    }
};



