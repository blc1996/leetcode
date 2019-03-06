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
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL){
            return vector<vector<int>>();
        }
        vector<vector<int>> output(1, vector<int>());
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        int index = 0;
        while(!q.empty()){
            Node* cur = q.front();
            q.pop();
            if(cur == NULL){
                if(q.empty()){
                    break;
                }else{
                    q.push(NULL);
                    index++;
                    output.push_back(vector<int>());
                    continue;
                }
            }
            output[index].push_back(cur->val);
            for(Node* i : cur->children){
                if(i != NULL){
                    q.push(i);
                }
            }
        }
        return output;
    }
};