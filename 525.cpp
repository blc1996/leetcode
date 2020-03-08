class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int dpVal = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        int maxCount = 0;
        for(int i = 0; i < nums.size(); i++){
            dpVal = nums[i] ? dpVal + 1 : dpVal - 1;
            if(mp.count(dpVal)){
                maxCount = max(maxCount, i - mp[dpVal]);
            }else{
                mp[dpVal] = i;
            }
        }
        return maxCount;
    }
};