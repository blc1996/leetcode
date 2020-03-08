class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<unsigned long long>> dp(m + 2, vector<unsigned long long>(n + 2, 0));
        dp[i+1][j+1] = 1;
        for(int i = N; i > 0; i--){
            updateMap(dp);
        }
        unsigned long long sum = 0;
        for(int i = 0; i < n + 2; i++){
            sum += dp[0][i] + dp[m+1][i];
            sum %= 1000000007;
        }
        for(int i = 0; i < m + 2; i++){
            sum += dp[i][0] + dp[i][n + 1];
            sum %= 1000000007;
        }
        return sum;
    }

    void updateMap(vector<vector<unsigned long long>>& dp){
        int h = dp.size() - 1, w = dp[0].size() - 1;
        vector<vector<unsigned long long>> tempDp = dp;
        for(int i = 1; i < h; i++){
            for(int j = 1; j < w; j++){
                 dp[i][j] = 0;
            }
        }
        for(int i = 1; i < h; i++){
            for(int j = 1; j < w; j++){
                if(tempDp[i][j]){
                    dp[i-1][j] += tempDp[i][j];
                    dp[i-1][j] %= 1000000007;
                    dp[i+1][j] += tempDp[i][j];
                    dp[i+1][j] %= 1000000007;
                    dp[i][j-1] += tempDp[i][j];
                    dp[i][j-1] %= 1000000007;
                    dp[i][j+1] += tempDp[i][j];
                    dp[i][j+1] %= 1000000007;
                }
            }
        }
    }
};