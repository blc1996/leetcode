class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result;
        unordered_set<int> set;
        for(int i : nums){
            if(set.count(i) == 0)
                set.insert(i);
            else
                set.erase(i);
        }
        for(int i : nums){
            if(set.count(i) != 0)
                result.push_back(i);
        }
        return result;
    }
};
