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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return partition(lists, 0, lists.size() - 1);
    }

    // partition and use merge sort
    ListNode* partition(vector<ListNode*>& lists, int left, int right){
        if(left == right)
            return lists[left];
        int mid = left + (right - left)/2;
        return merge(partition(left, mid), partition(lists, mid + 1, right));
    }

    ListNode* merge(ListNode* node1, ListNode* node2){
        ListNode initial(0);
        ListNode* cur = &initial;
        while(node1 || node2){
            if(!node1){
                cur->next = node2;
                node2 = node2->next;
            }else if(!node2){
                cur->next = node1;
                node1 = node1->next;
            }else if(node1->val > node2->val){
                cur->next = node2;
                node2 = node2->next;
            }else{
                cur->next = node1;
                node1 = node1->next;
            }
            cur = cur->next;
        }
        return initial.next;
    }
};
