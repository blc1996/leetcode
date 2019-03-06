/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> map;
        RandomListNode* cur = head;
        RandomListNode initial(0);
        RandomListNode* out = &initial;
        while(cur != NULL){
            if(map.count(cur))
                out->next = map[cur];
            else
                out->next = new RandomListNode(cur->label);
            if(map.count(cur->random))
                out->next->random = map[cur->random];
            else{
                out->next->random = cur->random ? new RandomListNode(cur->random->label) : NULL;
            }
            map[cur] = out->next;
            map[cur->random] = out->next->random;
            cur = cur->next;
            out = out->next;
        }
        return initial.next;
    }
};
