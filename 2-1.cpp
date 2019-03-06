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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, temp1 = 0, temp2 = 0;
        ListNode initial(0);
        ListNode* out = &initial;
        ListNode *cur1 = l1, *cur2 = l2;
        while(cur1 != NULL || cur2 != NULL){
            if(cur1 != NULL){
                temp1 = cur1->val;
                cur1 = cur1->next;
            }else{
                temp1 = 0;
            }
            if(cur2 != NULL){
                temp2 = cur2->val;
                cur2 = cur2->next;
            }else{
                temp2 = 0;
            }
            out->next = new ListNode((temp1 + temp2 + carry) % 10);
            out = out->next;
            carry = (temp1 + temp2 + carry) / 10;
        }
        if(carry == 1)
            out->next = new ListNode(1);
        return initial.next;
    }
};

