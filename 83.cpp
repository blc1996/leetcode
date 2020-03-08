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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head){
            return head;
        }
        ListNode initial = ListNode(head->val ? 0 : 1);
        initial.next = head;
        ListNode* prev = &initial, *curNode = head;
        while(curNode){
            if(curNode->val == prev->val){
                prev->next = curNode->next;
            }else{
                prev = prev->next;
            }
            curNode = curNode->next;
        }
        return initial.next;
    }
};