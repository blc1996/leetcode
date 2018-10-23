class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++){
            // if(m.count(nums.at(i)) > 0 && 2 * nums.at(i) == target){
            //     return {m[nums.at(i)], i};
            // }
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
