/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return NULL;
        auto ret = treeToDoublyListCore(root);
        ret.first->left = ret.second;
        ret.second->right = ret.first;
        return ret.first;
    }

    pair<Node*, Node*> treeToDoublyListCore(Node* root) {
        Node* leftRet = root, *rightRet = root;
        if(root->left){
            auto leftSubTree = treeToDoublyListCore(root->left);
            leftSubTree.second->right = root;
            root->left = leftSubTree.second;
            leftRet = leftSubTree.first;
        }
        if(root->right){
            auto rightSubTree = treeToDoublyListCore(root->right);
            rightSubTree.first->left = root;
            root->right = rightSubTree.first;
            rightRet = rightSubTree.second;
        }
        leftRet->left = NULL;
        rightRet->right = NULL;
        return pair<Node*, Node*>(leftRet, rightRet);
    }
};

{"$id":"1","left":{"$id":"2","left":{"$id":"3","left":{"$id":"4","left":{"$id":"5","left":{"$ref":"1"},"right":{"$ref":"4"},"val":2},"right":{"$ref":"3"},"val":3},"right":{"$ref":"2"},"val":4},"right":{"$ref":"1"},"val":5},"right":{"$ref":"5"},"val":1}