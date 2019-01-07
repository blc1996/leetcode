class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        store = vector<int>();
        mp = unordered_map<int, int>();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.count(val) != 0)
            return false;
        store.push_back(val);
        mp.insert({val, store.size() - 1});
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mp.count(val) == 0)
            return false;
        int index = mp[val];
        mp.erase(val);
        int back = store.back();
        store.pop_back();
        if(index < store.size()){
            store[index] = back;
            mp[back] = index;   
        }
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() { 
        int index = rand() % store.size();
        return store[index];
    }

    vector<int> store;
    unordered_map<int, int> mp;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */