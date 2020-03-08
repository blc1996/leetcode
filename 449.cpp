/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){
            return string();
        }
        vector<int> preorderElements;
        vector<int> inorderElements;
        inorderTraverse(root, inorderElements);
        preorderTraverse(root, preorderElements);
        string res;
        for(int i = 0; i < preorderElements.size(); i++){
            res.append(to_string(preorderElements[i]) + ',');
        }
        res.push_back('&');
        for(int i = 0; i < inorderElements.size(); i++){
            res.append(to_string(inorderElements[i]) + ',');
        }
        return res;
    }

    void inorderTraverse(TreeNode* node, vector<int>& res){
        if(!node){
            return;
        }
        inorderTraverse(node->left, res);
        res.push_back(node->val);
        inorderTraverse(node->right, res);
    }

    void preorderTraverse(TreeNode* node, vector<int>& res){
        if(!node){
            return;
        }
        res.push_back(node->val);
        preorderTraverse(node->left, res);
        preorderTraverse(node->right, res);
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0){
            return NULL;
        }
        int index = data.find_first_of('&');
        string pre = data.substr(0, index);
        string in = data.substr(index + 1);
        vector<int> preorderElements = toVector(pre);
        vector<int> inorderElements = toVector(in);
        return reconstructBST(preorderElements, inorderElements);
    }


    vector<int> toVector(string s){
        vector<int> res;
        int prevIdx = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ','){
                res.push_back(stoi(s.substr(prevIdx, i - prevIdx)));
                prevIdx = ++i;
            }
        }
        return res;
    }

    TreeNode* reconstructBST(vector<int> pre, vector<int> in){
        TreeNode* node = new TreeNode(pre[0]);
        int index = 0;
        for(int i = 0; i < in.size(); i++){
            if(in[i] == pre[0]){
                index = i;
                break;
            }
        }
        if(index > 0)
            node->left = reconstructBST(vector<int>(pre.begin() + 1, pre.begin() + 1 + index), vector<int>(in.begin(), in.begin() + index));
        if(index < in.size() - 1)
            node->right = reconstructBST(vector<int>(pre.begin() + 1 + index, pre.end()), vector<int>(in.begin() + index + 1, in.end()));
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));