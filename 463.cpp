class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.size() == 0){
            return 0;
        }
        int h = grid.size(), w = grid[0].size();
        int res = 0;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(grid[i][j]){
                    if(i == 0 || !grid[i - 1][j]){
                        res++;
                    }
                    if(i == h - 1 || !grid[i + 1][j]){
                        res++;
                    }
                    if(j == 0 || !grid[i][j - 1]){
                        res++;
                    }
                    if(j == w - 1 || !grid[i][j + 1]){
                        res++;
                    }
                }
            }
        }
        return res;
    }
};