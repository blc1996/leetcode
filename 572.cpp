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
    void constructTreeStr(TreeNode* node, string& s){
        if(node == NULL){
            s.append(" #,");
            return;
        }
        s.append(" " + to_string(node->val) + ",");
        constructTreeStr(node->left, s);
        constructTreeStr(node->right, s);
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        string tree1, tree2;
        constructTreeStr(s, tree1);
        constructTreeStr(t, tree2);
        if(tree1.find(tree2) != -1){
            return true;
        }else{
            return false;
        }
    }
};

class Solution {
public:
    bool compareNode(TreeNode* s, TreeNode* t){
        if(s == NULL && t == NULL) return true;
        if(s != NULL && t == NULL) return false;
        if(s == NULL && t != NULL) return false;
        if(s->val != t->val) return false;
        return compareNode(s->left, t->left) && compareNode(s->right, t->right);
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == NULL){
            return t == NULL;
        }
        return compareNode(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};