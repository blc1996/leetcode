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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode* curA = headA, *curB = headB;
        while(curA){
            lenA++;
            curA = curA->next;
        }
        while(curB){
            lenB++;
            curB = curB->next;
        }
        curA = headA; curB = headB;
        if(lenA > lenB){
            for(int i = 0; i < lenA - lenB; i++){
                curA = curA->next;
            }
        }else{
            for(int i = 0; i < lenB - lenA; i++){
                curB = curB->next;
            }
        }
        while(curB != curA){
            curA = curA->next;
            curB = curB->next;
        }
        return curA;
    }
};
