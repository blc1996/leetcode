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
        ListNode* initial = new ListNode(0);
        int length1 = getLength(l1), length2 = getLength(l2);
        ListNode* cur1 = l1, *cur2 = l2;
        if(length1 > length2){
            for(int i = 0; i < length1 - length2; i++){
                cur1 = cur1->next;
            }
        }else{
            for(int i = 0; i < length2 - length1; i++){
                cur2 = cur2->next;
            }
        }
        addRecursively(cur1, cur2, initial);
        if(length1 > length2){
            addRecursivelySingle(l1, length1 - length2, initial);
        }else if(length1 < length2){
            addRecursivelySingle(l2, length2 - length1, initial);
        }
        if(initial->val == 1){
            ListNode* tempNode = new ListNode(1);
            tempNode->next = initial->next;
            initial->next = tempNode;
        }
        return initial->next;
    }

    int getLength(ListNode* node){
        int length = 0;
        while(node){
            length++;
            node = node->next;
        }
        return length;
    }

    void addRecursivelySingle(ListNode* node1, int count, ListNode* initial){
        if(count > 1){
            addRecursivelySingle(node1->next, count - 1, initial);
        }
        int val = node1->val + initial->val;
        initial->val = val / 10;
        ListNode* tempNode = new ListNode(val % 10);
        tempNode->next = initial->next;
        initial->next = tempNode;
    }

    void addRecursively(ListNode* node1, ListNode* node2, ListNode* initial){
        if(node1->next){
            addRecursively(node1->next, node2->next, initial);
        }
        int val = node1->val + node2->val + initial->val;
        initial->val = val / 10;
        ListNode* tempNode = new ListNode(val % 10);
        tempNode->next = initial->next;
        initial->next = tempNode;
    }
};