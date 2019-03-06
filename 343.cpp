class Solution {
public:
    int integerBreak(int n) {
        if(n == 2)
            return 1;
        if(n == 3)
            return 2;
        vector<int> dp(n+1, 0);
        return helper(n, dp);
    }

    int helper(int n, vector<int>& dp){
        if(dp[n] != 0)
            return dp[n];
        dp[2] = 2;
        dp[3] = 3;
        int maxVal = 0;
        for(int i = 2; i <= n/2; i++){
            maxVal = max(maxVal, helper(i, dp) * helper(n - i, dp));
        }
        dp[n] = maxVal;
        return maxVal;
    }
};
