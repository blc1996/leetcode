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
    ListNode* sortList(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode* current = head;
        while(current->next != NULL)
            current = current->next;
        return mergesort(head, current);
    }

    ListNode* mergesort(ListNode* start, ListNode* end){
        if(start == end)
            return start;
        ListNode* mid = findMid(start, end);
        ListNode* rstart = mid->next;
        mid->next = NULL;
        ListNode* left = mergesort(start, mid);
        ListNode* right = mergesort(rstart, end);
        ListNode* dummy = new ListNode(0), *out  = dummy;
        while(left != NULL && right != NULL){
            if(left->val < right->val){
                out->next = left;
                out = out->next;
                left = left->next;
            }else{
                out->next = right;
                out = out->next;
                right = right->next;
            }
        }
        if(left != NULL)
            out->next = left;
        else if(right != NULL)
            out->next = right;
        return dummy->next;
    }

    ListNode* findMid(ListNode* start, ListNode* end){
        ListNode* fast = start, *slow = start;
        while(fast != end && fast->next != end){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};
