class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(9, false));
        vector<vector<bool>> cols(9, vector<bool>(9, false));
        vector<vector<bool>> blocks(9, vector<bool>(9, false));
        for(int x = 0; x < 9; x++){
            for(int y = 0; y < 9; y++){
                if(board[x][y] != '.'){
                    int num = board[x][y] - '1';
                    rows[x][num] = true;
                    cols[y][num] = true;
                    blocks[(x / 3) * 3 + (y / 3)][num] = true;
                }
            }
        }
        backtrack(board, 0, 0, rows, cols, blocks);
    }

    bool backtrack(vector<vector<char>>& board, int x, int y, vector<vector<bool>>& rows, vector<vector<bool>>& cols, vector<vector<bool>>& blocks){
        if(x >= 9 ) return true;
        int nextX = x + (y + 1) / 9, nextY = (y + 1) % 9;
        // cout<<x<<" "<<y<<" "<<nextX<<" "<<nextY<<endl;
        if(board[x][y] == '.'){
            for(int i = 1; i <= 9; i++){
                if(rows[x][i - 1] || cols[y][i - 1] || blocks[(x / 3) * 3 + (y / 3)][i - 1]){
                    continue;
                }
                board[x][y] = i + '0';
                rows[x][i - 1] = true;
                cols[y][i - 1] = true;
                blocks[(x / 3) * 3 + (y / 3)][i - 1] = true;
                if(backtrack(board, nextX, nextY, rows, cols, blocks)){
                    return true;
                }else{
                    board[x][y] = '.';
                    rows[x][i - 1] = false;
                    cols[y][i - 1] = false;
                    blocks[(x / 3) * 3 + (y / 3)][i - 1] = false;
                }
            }
        }else{
            return backtrack(board, nextX, nextY, rows, cols, blocks);
        }
        return false;
    }
};