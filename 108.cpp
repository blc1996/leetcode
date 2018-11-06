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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }

    TreeNode* helper(vector<int>& nums, int left, int right){
        if(left > right)
            return NULL;

        int index = (left + right) / 2;
        TreeNode* output = new TreeNode(nums[index]);

        output->left = helper(nums, left, index - 1);
        output->right = helper(nums, index + 1, right);
        return output;
    }
};
