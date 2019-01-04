class Solution {
public:
    unordered_map<int, vector<int>> mp;

    Solution(vector<int> nums) {
        for(int i = 0; i < nums.size(); i++){
            if(mp.count(nums[i]) == 0)
                mp.insert({nums[i], vector<int>()});
            mp[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
        if(mp.count(target) == 0)
            return -1;
        int size = mp[target].size();
        int idx = rand() % size;
        return mp[target][idx];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
