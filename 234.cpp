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
    bool isPalindrome(ListNode* head) {
        int count = 0;
        ListNode* current = head;
        while(current){
            count++;
            current = current->next;
        }
        if(count <= 1)
            return true;
        int temp = count;
        count = count / 2;
        current = head;
        while(count){
            current = current->next;
            count--;
        }
        return helper(head, (temp - 1) / 2, current);
    }

    bool helper(ListNode* node, int step, ListNode*& current){
        if(step && !helper(node->next, step - 1, current))
            return false;

        if(current->val != node->val)
            return false;
        current = current->next;
        return true;
    }
};
