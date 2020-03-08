class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        if(grid.size() == 0){
            return 0;
        }
        int height = grid.size(), width = grid[0].size();
        vector<int> colMaxHeight(height, 0), rowMaxHeight(width, 0);
        for(int i = 0; i < height; i++){
            colMaxHeight[i] = *max_element(grid[i].begin(), grid[i].end());
        }
        for(int i = 0; i < width; i++){
            int maxElem = 0;
            for(int j = 0; j < height; j++){
                maxElem = max(maxElem, grid[j][i]);
            }
            rowMaxHeight[i] = maxElem;
        }
        int res = 0;
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                res += min(colMaxHeight[i], rowMaxHeight[j]) - grid[i][j];
            }
        }
        return res;
    }
};