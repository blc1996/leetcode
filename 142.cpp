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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL)
            return NULL;
        ListNode* slow = head, *fast = head->next;
        bool flag = true;
        while(slow->next != NULL && fast->next != NULL){
            if(slow == fast){
                ListNode* third = head;
                fast = fast->next;
                while(1){
                    if(fast == third)
                        return third;
                    if(fast == slow)
                        third = third->next;
                    fast = fast->next;
                }
            }
            if(flag){
                slow = slow->next;
            }
            flag = !flag;
            fast = fast->next;
        }
        return NULL;
    }
};


//faster version
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast)
                break;
        }
        if(fast == NULL || fast->next == NULL)
            return NULL;

        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};
