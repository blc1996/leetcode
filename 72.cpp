class Solution {
public:

    int minDistanceCore(string word1, string word2, bool flag) {
        if(word1.size() == 0 || word2.size() == 0){
            return max(word1.size(), word2.size());
        }
        int res = INT_MAX;
        if(flag || word1.size() < word2.size()){
            for(int i = 0; i < word2.size(); i++){
                auto temp = word2;
                temp.erase(temp.begin() + i);
                res = min(res, minDistanceCore(word1, temp, true) + 1);
            }
        }
        
        if(flag){
            res = min(res, minDistanceCore(word2, word1, false));
        }
        
        if(word1.size() == word2.size()){
            int tempRes = 0;
            for(int i = 0; i < word1.size(); i++){
                if(word1[i] != word2[i]) tempRes++;
            }
            res = min(res, tempRes);
        }
        return res;
    }

    int minDistance(string word1, string word2) {
        return minDistanceCore(word1, word2, true);
    }
};

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= n; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
            }
        }
        return dp[m][n];
    }
};