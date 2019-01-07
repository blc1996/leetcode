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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        head_ = head;
        size = 0;
        while(current != NULL){
            current = current->next;
            size++;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode* current = head_; 
        int step = rand() % size;
        for(int i = 0; i < step; i++)
            current = current->next;
        return current->val;
    }
private:
    int size;
    ListNode* head_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */