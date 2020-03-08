class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++){
            m[nums.at(i)] = i;
        }

        for(int i = 0; i < nums.size(); i++){
            if(m.count(target - nums.at(i)) > 0){
                if(i != m[target - nums.at(i)])
                    return {i, m[target - nums.at(i)]};
            }
        }

        return {};
    }
};


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            if(mp.count(target - nums[i])){
                return {mp[target - nums[i]], i};
            }
            mp.insert({nums[i], i});
        }
        return {};
    }
};