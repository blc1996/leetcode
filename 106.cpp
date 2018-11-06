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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(preorder, inorder, postorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int pIndex, int iLeft, int iRight){
        if(iLeft > iRight || pIndex < 0)
            return NULL;
        if(iLeft == iRight)
            return new TreeNode(inorder[iLeft]);

        int index = iLeft;
        while(preorder[pIndex] != inorder[index])
            index++;

        TreeNode* output = new TreeNode(preorder[pIndex]);
        output->left = helper(preorder, inorder, pIndex - iRight + index - 1, iLeft, index - 1);
        output->right = helper(preorder, inorder, pIndex - 1, index + 1, iRight);
        return output;
    }
};
