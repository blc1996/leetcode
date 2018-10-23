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
    ListNode* partition(ListNode* head, int x) {
        ListNode *placeHolder = new ListNode(0), *currentNode = NULL;
        placeHolder->next = head;
        head = placeHolder;

        while(placeHolder->next != NULL && placeHolder->next->val < x){
            placeHolder = placeHolder->next;
        }

        currentNode = placeHolder;

        while(currentNode->next != NULL){
            if(currentNode->next->val < x){
                ListNode *tempNode = currentNode->next;
                currentNode->next = currentNode->next->next;
                tempNode->next = placeHolder->next;
                placeHolder->next = tempNode;
                placeHolder = placeHolder->next;
            }else{
                currentNode = currentNode->next;
            }
        }

        return head->next;
    }
};
