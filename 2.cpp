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
        ListNode *currentNode1 = l1, *currentNode2 = l2, *tempNode = new ListNode(0), *outputNode = tempNode;
        int carry = 0;
        while(currentNode1 != NULL || currentNode2 != NULL){

            int val1 = currentNode1 == NULL ? 0 : currentNode1->val;
            int val2 = currentNode2 == NULL ? 0 : currentNode2->val;

            tempNode->next = new ListNode((val1 + val2 + carry) % 10);
            tempNode = tempNode->next;

            carry = (carry + val1 + val2) / 10;
        }

        if(carry == 1){
            tempNode->next = new ListNode(1);
        }

        return outputNode->next;
    }
};
