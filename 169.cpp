class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        for(unsigned i = 0; i < nums.size(); i++){
                m[nums[i]]++;
        }
        int bar = nums.size() / 2;
        for(unsigned i = 0; i < nums.size(); i++){
            if(m[nums[i]] > bar)
                return nums[i];
        }
        return 0;
    }
};
