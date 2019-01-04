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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL)
            return vector<string>();
        vector<string> output;
        string temp;
        DFS(root, output, temp);
        return output;
    }

    void DFS(TreeNode* node, vector<string>& output, string& temp){
        if(node->left == NULL && node->right == NULL){
            temp += to_string(node->val);
            output.push_back(temp);
            while(temp.size() > 0 && temp[temp.size() - 1] != '>')
                temp.pop_back();
            return;
        }
        temp += to_string(node->val) + "->";

        if(node->left){
            DFS(node->left, output, temp);
        }
        if(node->right){
            DFS(node->right, output, temp);
        }

        temp.pop_back();
        while(temp.size() > 0 && temp[temp.size() - 1] != '>')
            temp.pop_back();
        return;
    }
};
