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
        if(head == NULL)
            return NULL;
        unordered_map<RandomListNode *, RandomListNode *> m;
        unordered_set<RandomListNode *> s;
        queue<RandomListNode *> q;
        RandomListNode* copy = new RandomListNode(head->label);
        m[head] = copy;
        q.push(head);
        while(!q.empty()){
            RandomListNode* temp = q.front();
            q.pop();
            if(s.count(temp))
                continue;
            if(temp->next != NULL){
                if(m.count(temp->next)){
                    m[temp]->next = m[temp->next];
                }else{
                    m[temp]->next = new RandomListNode(temp->next->label);
                    m[temp->next] = m[temp]->next;
                }
                q.push(temp->next);
            }
            if(temp->random != NULL){
                if(m.count(temp->random)){
                    m[temp]->random = m[temp->random];
                }else{
                    m[temp]->random = new RandomListNode(temp->random->label);
                    m[temp->random] = m[temp]->random;
                }
                q.push(temp->random);
            }
            s.insert(temp);
        }
        return copy;
    }
};
