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


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return NULL;
        ListNode *initial = new ListNode(0);
        initial->next = head;
        ListNode *cur = initial, *nxt, *prev = initial;
        int nodeNum = 0;
        while(cur = cur->next) nodeNum++;
        while(nodeNum >= k){
            cur = prev->next;
            nxt = cur->next;
            for(int i = 1; i < k; i++){
                cur->next = nxt->next;
                nxt->next = prev->next;
                prev->next = nxt;
                nxt = cur->next;
            }
            prev = cur;
            nodeNum -= k;
        }
        return initial->next;
    }
};
