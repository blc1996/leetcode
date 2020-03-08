class LRUCache {
    typedef struct ListNode{
        int key;
        int value;
        ListNode* prev;
        ListNode* next;

        ListNode(int k, int v){
            key = k;
            value = v;
            prev = NULL;
            next = NULL;
        }
    }ListNode;


public:
    LRUCache(int capacity) {
        _mp = unordered_map<int, ListNode*>();
        _capacity = capacity <= 0 ? 100 : capacity;
        _size = 0;
        head = NULL;
    }
    
    int get(int key) {
        if(_mp.count(key)){
            ListNode* curNode = _mp[key];
            if(curNode != head){
                curNode->next->prev = curNode->prev;
                curNode->prev->next = curNode->next;
                curNode->prev = head->prev;
                curNode->next = head;
                head->prev->next = curNode;
                head->prev = curNode;
                head = curNode;
            }
            return curNode->value;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(!_mp.count(key)){
            if(_size >= _capacity){
                ListNode* lastNode = head->prev;
                ListNode* curNode = head;
                if(lastNode == head){
                    head = NULL;
                }else{
                    lastNode->prev->next = lastNode->next;
                    lastNode->next->prev = lastNode->prev;
                }
                _mp.erase(lastNode->key);
                delete lastNode;
                _size--;
            }
            ListNode* tempNode = new ListNode(key, value);
            if(head){
                tempNode->prev = head->prev;
                tempNode->next = head;
                head->prev->next = tempNode;
                head->prev = tempNode;
            }else{
                tempNode->next = tempNode;
                tempNode->prev = tempNode;
            }
            head = tempNode;
            _mp.insert({key, tempNode});
            _size++;
        }else{
            _mp[key]->value = value;
            get(key);
        }
    }
private:
    unordered_map<int, ListNode*> _mp;
    ListNode* head;
    int _capacity;
    int _size;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */