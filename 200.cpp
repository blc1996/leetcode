// class Solution {
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         if(grid.size() == 0)
//             return 0;
//         int num = 0;
//         vector<vector<int>> board(grid.size() + 1, vector<int>(grid[0].size() + 1, INT_MAX));
//         for(int i = 0; i < grid.size(); i++){
//             for(int j = 0; j < grid[0].size(); j++){
//                 if(grid[i][j] == '1'){
//                     int left, up;
//                     if(i == 0 && j == 0){
//                         left = '0';
//                         up = '0';
//                     }else if(i == 0){
//                         up = '0';
//                         left = grid[0][j - 1];
//                     }else if(j == 0){
//                         left = '0';
//                         up = grid[i - 1][0];
//                     }else{
//                         left = grid[i][j - 1];
//                         up = grid[i - 1][j];
//                     }
//                     if(left == '0' && up == '0'){
//                         num++;
//                         board[i + 1][j + 1] = num;
//                     }else{
//                          board[i + 1][j + 1] = min(board[i][j + 1], board[i + 1][j]);
//                         if(left == '1' && up == '1'){
//                             if()
//                         }
//                     }

//                 }
//             }
//         }
//         return num;
//     }
// };


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0)
            return 0;
        int num = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    num++;
                    helper(i, j, grid);
                }
            }
        }
        return num;
    }

    void helper(int i, int j, vector<vector<char>>& grid){
        if(grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        if(i + 1 < grid.size()){
            helper(i + 1, j, grid);
        }
        if(j + 1 < grid[0].size()){
            helper(i, j + 1, grid);
        }
        if(i - 1 >= 0){
            helper(i - 1, j, grid);
        }
        if(j - 1 >= 0){
            helper(i, j - 1, grid);
        }
    }
};
