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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, 0, inorder.size() - 1);
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int pIndex, int iLeft, int iRight){
        if(iLeft > iRight || pIndex >= preorder.size())
            return NULL;
        if(iLeft == iRight)
            return new TreeNode(inorder[iLeft]);

        int index = iLeft;
        while(preorder[pIndex] != inorder[index])
            index++;

        TreeNode* output = new TreeNode(preorder[pIndex]);
        output->left = helper(preorder, inorder, pIndex + 1, iLeft, index - 1);
        output->right = helper(preorder, inorder, pIndex + index - iLeft + 1, index + 1, iRight);
        return output;
    }
};
