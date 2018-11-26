/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution { //iteratively
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* current = head, *output = NULL;
        while(current != NULL){
            ListNode* temp = new ListNode(current->val);
            temp->next = output;
            output = temp;
            current = current->next;
        }
        return output;
    }
};


class Solution { //recursively
public:
    ListNode* reverseList(ListNode* head) {
        return helper(head, NULL);
    }

    ListNode* helper(ListNode* current, ListNode* result){
        if(current == NULL)
            return result;
        ListNode* temp = new ListNode(current->val);
        temp->next = result;
        return helper(current->next, temp);
    }
};
