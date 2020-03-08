/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL){
            return;
        }
        ListNode* initial = head;
        bool stopFlag = false;
        reorderListCore(head, initial, stopFlag);
    }

    void reorderListCore(ListNode*& node, ListNode*& initial, bool& stopFlag){
        if(!node){
            return;
        }
        reorderListCore(node->next, initial, stopFlag);
        if(initial == node) stopFlag = true;
        if(!stopFlag && node->next == NULL){
            ListNode* tempNode = node;
            node = NULL;
            tempNode->next = initial->next;
            initial->next = tempNode;
            initial = tempNode->next;
        }
    }
};