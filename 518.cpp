class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[amount + 1] = { 0 };
        dp[0] = 1;
        for (auto c : coins)
            for (auto j = c; j <= amount; ++j) dp[j] += dp[j - c];
        return dp[amount];
    }
};