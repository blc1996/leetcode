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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> set;
        ListNode* current = head;
        while(current != NULL){
            if(set.count(current))
                return true;
            set.insert(current);
            current = current->next;
        }
        return false;
    }
}; //O(n) space

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        ListNode* slow = head, *fast = head->next;
        bool flag = true;
        while(slow->next != NULL && fast->next != NULL){
            if(slow == fast)
                return true;
            if(flag){
                slow = slow->next;
            }
            flag = !flag;
            fast = fast->next;
        }
        return false;
    }
}; // O(1) space
