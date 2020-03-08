class Solution {
public:

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> counts;
        for(string s : strs){
            counts.push_back(countString(s));
        }
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        dp[0][0] = 0;
        int maxVal = 0;
        for(auto p : counts){
            vector<vector<int>> newDP(dp);
            for(int i = 0; i <= m; i++ ){
                for(int j = 0; j <= n; j++){
                    if( (i - p.first >= 0) && (j - p.second >= 0) && dp[i - p.first][j - p.second] >= 0){
                        newDP[i][j] = max(dp[i][j], dp[i - p.first][j - p.second] + 1);
                    }
                    maxVal = max(maxVal, newDP[i][j]);
                }
            }
            dp = newDP;
        }
        return maxVal;
    }

    pair<int, int> countString(const string& str){
        int zeros = 0, ones = 0;
        for(int i = 0; i < str.size(); i++){
            if(str[i] == '0')
                zeros++;
            else
                ones++;
        }
        return pair<int, int>(zeros, ones);
    }
};