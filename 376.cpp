class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 2)
            return nums.size();
        vector<int> dp(nums.size(), 0);
        dp[0] = 1; dp[1] = 2;
        bool flag = true;
        int max1 = 0, max2 = 0;
        for(int i = 2; i < nums.size(); i++){
            if((nums[i] - nums[i-1] < 0 && nums[i-1] - nums[i-2] > 0) 
                || (nums[i] - nums[i-1] > 0 && nums[i-1] - nums[i-2] < 0)){
                dp[i] = dp[i-1] + 1;
            }else{
                if(flag){
                    max1 += dp[i-1];
                }else{
                    max2 += dp[i-1];
                }
                flag = !flag;
                dp[i] = 2;
            }
        }
        if(flag){
            max1 += dp[nums.size() - 1];
        }else{
            max2 += dp[nums.size() - 1];
        }
        return max(max1, max2);
    }
};