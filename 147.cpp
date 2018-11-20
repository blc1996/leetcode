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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode* current = head->next, *prev = head;
        while(current != NULL){
            ListNode* temp = head;
            while(temp != current){
                if(current->val < head->val){
                    prev->next = current->next;
                    current->next = head;
                    head = current;
                    current = prev->next;
                    break;
                }
                if(temp->next == current){
                    prev = current;
                    break;
                }
                if(current->val <= temp->next->val){
                    prev->next = current->next;
                    current->next = temp->next;
                    temp->next = current;
                    current = prev->next;
                    break;
                }
                temp = temp->next;
            }
            current = prev->next;
        }
        return head;
    }
};
