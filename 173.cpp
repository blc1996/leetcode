/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    TreeNode* current;
    stack<TreeNode *> st;

    BSTIterator(TreeNode *root) {
        current = root;
        if(current == NULL)
            return;
        while(current->left != NULL){
            st.push(current);
            current = current->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return current != NULL;
    }

    /** @return the next smallest number */
    int next() {
        int out = current->val;
        if(current->right != NULL){
            current = current->right;
            while(current->left != NULL){
                st.push(current);
                current = current->left;
            }
        }else if(!st.empty()){
            current = st.top();
            st.pop();
        }else{
            current = NULL;
        }
        return out;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */



/*
recursive
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    vector<int> vals;
    unsigned ptr;

    BSTIterator(TreeNode *root) {
        vals = vector<int>();
        ptr = 0;

        helper(root);
    }

    void helper(TreeNode* root){
        if(root == NULL)
            return;

        helper(root->left);
        vals.push_back(root->val);
        helper(root->right);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return ptr < vals.size();
    }

    /** @return the next smallest number */
    int next() {
        int temp = vals[ptr];
        ptr++;
        return temp;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

