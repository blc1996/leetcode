class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int threshold = nums.size() / 3;
        unordered_map<int, int> mp;
        for(int i : nums){
            mp[i]++;
        }
        for(auto it = mp.begin(); it != mp.end(); it++){
            if(it->second > threshold) res.push_back(it->first);
        }
        return res;
    }
};