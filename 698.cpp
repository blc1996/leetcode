class Solution {
public:
    bool searchCore(vector<int>& rem, vector<int>& nums, int index){
        if(index >= nums.size()) return true;
        for(int i = 0; i < rem.size(); i++){
            if(rem[i] >= nums[index]){
                rem[i] -= nums[index];
                if(searchCore(rem, nums, index + 1)) return true;
                rem[i] += nums[index];
            }
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(int i : nums){
            sum += i;
        }
        if(sum % k != 0) return false;
        sort(nums.begin(), nums.end(), [](auto a, auto b){return a > b;});
        vector<int> rem(k, sum / k);
        return searchCore(rem, nums, 0);
    }
};