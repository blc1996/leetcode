class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0){
            return 0;
        }
        int res = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                res = max(res, findLongest(matrix, dp, i, j));
            }
        }
        return res;
    }

    int findLongest(vector<vector<int>>& matrix, vector<vector<int>>& dp, int x, int y){
        if(dp[x][y]){
            return dp[x][y];
        }
        
        int res = 0;
        int curNum = matrix[x][y];
        if(x - 1 >= 0 && matrix[x-1][y] > curNum){
            res = max(res, dp[x-1][y] ? dp[x-1][y] : findLongest(matrix, dp, x-1, y));
        }
        if(x + 1 < matrix.size() && matrix[x+1][y] > curNum){
            res = max(res, dp[x+1][y] ? dp[x+1][y] : findLongest(matrix, dp, x+1, y));
        }
        if(y - 1 >= 0 && matrix[x][y-1] > curNum){
            res = max(res, dp[x][y-1] ? dp[x][y-1] : findLongest(matrix, dp, x, y-1));
        }
        if(y + 1 < matrix[0].size() && matrix[x][y+1] > curNum){
            res = max(res, dp[x][y+1] ? dp[x][y+1] : findLongest(matrix, dp, x, y+1));
        }
        dp[x][y] = res + 1;
        return res + 1;
    }
};