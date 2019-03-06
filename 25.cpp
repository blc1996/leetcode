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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL)
            return NULL;
        ListNode *initial = new ListNode(0);
        initial->next = head;
        ListNode *left = initial, *right = initial;
        while(left){
            for(int j = 0; j < k - 1; j++){
                right = left;
                for(int i = 0; i < k - 1 - j; i++){
                    right = right->next;
                    if(right == NULL || right->next == NULL){
                        return initial->next;
                    }
                }
                ListNode *temp = right->next;
                right->next = right->next->next;
                temp->next = left->next;
                left->next = temp;
                left = left->next;
            }
            left = left->next;
        }
        return initial->next;
    }
};
