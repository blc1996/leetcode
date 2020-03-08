/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if(!head){
            return head;
        }
        Node* tempNode = head;
        while(tempNode){
            if(tempNode->child){
                Node* newHead = flatten(tempNode->child);
                Node* newTail = newHead;
                while(newTail->next){
                    newTail = newTail->next;
                }
                tempNode->child = NULL;
                newTail->next = tempNode->next;
                if(tempNode->next)
                    tempNode->next->prev = newTail;
                tempNode->next = newHead;
                newHead->prev = tempNode;
            }
            tempNode = tempNode->next;
        }
        return head;
    }
};