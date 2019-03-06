class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size() == 0)
            return 0;
        int count = 0;
        helper(obstacleGrid, 0, 0, count);
        return count;
    }

    void helper(vector<vector<int>>& obstacleGrid, int row, int col, int& count){
        if(obstacleGrid[row][col])
            return;
        if(row == obstacleGrid.size() - 1 && col == obstacleGrid[0].size() - 1){
                count++;
            return;
        }
        if(row != obstacleGrid.size() - 1){
            helper(obstacleGrid, row + 1, col, count);
        }
        if(col != obstacleGrid[0].size() - 1){
            helper(obstacleGrid, row, col + 1, count);
        }
    }
};
// time limit exceed
//


//dp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size() == 0)
            return 0;
        vector<vector<long>> dp(obstacleGrid.size(), vector<long>(obstacleGrid[0].size() , 0));
        for(int i = 0; i < obstacleGrid.size(); i++){
            if(obstacleGrid[i][0])
                break;
            dp[i][0] = 1;
        }
        for(int j = 0; j < obstacleGrid[0].size(); j++){
            if(obstacleGrid[0][j])
                break;
            dp[0][j] = 1;
        }
        for(int i = 1; i < obstacleGrid.size(); i++){
            for(int j = 1; j < obstacleGrid[0].size(); j++){
                if(obstacleGrid[i][j] != 1){
                    dp[i][j] = dp[i][j-1] + dp[i-1][j];
                }
            }
        }
        return dp[dp.size()-1][dp[0].size()-1];
    }
};
