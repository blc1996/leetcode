class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        store = vector<int>();
        mp = unordered_multimap<int, int>();
    }
    
   /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        store.push_back(val);
        mp.insert({val, store.size() - 1});
        if(mp.count(val) != 1)
            return false;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mp.count(val) == 0)
            return false;
        auto it = mp.find(val);
        int index = it->second;
        mp.erase(it);
        int back = store.back();
        store.pop_back();
        if(index < store.size()){
            store[index] = back;
            auto range = mp.equal_range(back);
            for(auto it1 = range.first; it1 != range.second; it1++){
                // cout<<it1->first<<" "<<it1->second<<endl;
                if(it1->second == store.size()){
                    it1->second = index;
                    break;
                }
            } 
        }
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int index = rand() % store.size();
        return store[index];
    }

    vector<int> store;
    unordered_multimap<int, int> mp;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */