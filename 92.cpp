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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *currentNode = new ListNode(0);
        currentNode->next = head;
        head = currentNode;
        int count = n - m;
        for(int i = 0; i < m; i++){
            currentNode = currentNode->next;
        }
        ListNode *tempNode = NULL;
        while(count >= 1){
            tempNode = currentNode;
            for(int i = 0; i < count; i++){
                tempNode = tempNode->next;
            }
            int temp = tempNode->val;
            tempNode->val = currentNode->val;
            currentNode->val = temp;
            currentNode = currentNode->next;
            count -= 2;
        }
        return head->next;
    }
};
