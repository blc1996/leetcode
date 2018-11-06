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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0){
            return vector<TreeNode *>();
        }
        return helper(1, n);
    }

    vector<TreeNode *> helper(int start, int end){
        std::vector<TreeNode *> output;

        if(start > end){
            output.push_back(NULL);
            return output;
        }

        if(start == end){
            output.push_back(new TreeNode(start));
            return output;
        }

        for(int i = start; i <= end; i++){
            vector<TreeNode *> left = helper(start, i - 1);
            vector<TreeNode *> right = helper(i + 1, end);

            for(auto it1 = left.begin(); it1 != left.end(); ++it1){
                for(auto it2 = right.begin(); it2 != right.end(); ++it2){
                    TreeNode *root = new TreeNode(i);
                    root->left = *it1;
                    root->right = *it2;
                    output.push_back(root);
                }
            }
        }

        return output;
    }
};
