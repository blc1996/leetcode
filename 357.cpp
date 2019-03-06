class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
         // a[0] = 1
        // a[1] = 9 + a[0]
        // a[2] = 9*9 + a[1]
        // a[3] = 9*9*8 + a[2]
        // a[4] = 9*9*8*7 + a[3]
        // ...
        // a[n] = 9*9!/(10 - n)! + a[n - 1]
        vector<int> dp(n + 1, 0);
        vector<int> remain(n + 1, 0);
        dp[0] = 1; dp[1] = 10;
        remain[1] = 0;
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + 9 * (dp[i-1] - remain[i-1]) - 9;
            remain[i] = 9*remain[i-1] + 9;
        }
        return dp[n-1];
    }
};