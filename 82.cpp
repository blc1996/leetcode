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
        ListNode* prev = &initial;
        while(prev->next && prev->next->next){
            if(prev->next->val == prev->next->next->val){
                ListNode* temp = prev->next->next;
                while(temp && prev->next->val == temp->val){
                    temp = temp->next;
                }
                prev->next = temp;
            }else{
                prev = prev->next;
            }
        }
        return initial.next;
    }
};