/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        int maxDepth = 1;
        queue<Node *> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            Node* curNode = q.front();
            q.pop();
            if(!curNode){
                if(q.empty()){
                    return maxDepth;
                }else{
                    maxDepth++;
                    q.push(NULL);
                }
            }else{
                for(Node* child : curNode->children){
                    if(child){
                        q.push(child);
                    }
                }
            }
        }
        return maxDepth;
    }
};