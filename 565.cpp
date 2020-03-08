class Solution {
public:
    int findLengthDFS(vector<int>& nums, int cur, vector<int>& dp){
        if(dp[cur]) return dp[cur];
        int maxLen = 0;
        if(nums[cur] != -1){
            int temp = nums[cur];
            nums[cur] = -1;
            maxLen = max(maxLen, findLengthDFS(nums, temp));
            nums[cur] = temp;
        }
        dp[cur] = maxLen + 1;
        return maxLen + 1;
    }


    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        vector<int> dp(n, 0);
        for(int i = 0; i < n; i++){
            res = max(res, findLengthDFS(nums, i, dp));
        }
        return res - 1;
    }
};