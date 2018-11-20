/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL)
            return;
        queue<pair<TreeLinkNode *, int>> q;
        q.push(pair<TreeLinkNode *, int>(root, 1));
        pair<TreeLinkNode*, int> prev = pair<TreeLinkNode *, int>(new TreeLinkNode(-1), 0);
        while(!q.empty()){
            pair<TreeLinkNode*, int> current = q.front();
            q.pop();
            if(current.first->left != NULL)
                q.push(pair<TreeLinkNode *, int>(current.first->left, current.second + 1));
            if(current.first->right != NULL)
                q.push(pair<TreeLinkNode *, int>(current.first->right, current.second + 1));

            if(prev.second == current.second){
                prev.first->next = current.first;
            }else{
                prev.first->next = NULL;
            }
            prev = current;
        }
        prev.first->next = NULL;
    }
};
