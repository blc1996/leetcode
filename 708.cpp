/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(!head){
            auto ret = new Node();
            ret->val = insertVal;
            ret->next = ret;
            return ret;
        }
        Node* curNode = head;
        while(curNode->next != head){
            if(curNode->val <= insertVal && curNode->next->val >= insertVal){
                break;
            }
            if(curNode->val > curNode->next->val && (insertVal <= curNode->next->val || insertVal >= curNode->val)){
                break;
            }
            curNode = curNode->next;
        }
        // insert after curNode
        auto temp = curNode->next;
        curNode->next = new Node(insertVal, temp);
        return head;
    }
};