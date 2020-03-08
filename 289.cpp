class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.size() == 0){
            return;
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                board[i][j] = calculateOneCell(board, i, j);
            }
        }
        
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == -3 || (board[i][j] >= 3 && board[i][j] <= 4)){
                    board[i][j] = 1;
                }else{
                    board[i][j] = 0;
                }
            }
        }
    }
    
    int calculateOneCell(vector<vector<int>>& board, int x, int y){
        int height = board.size(), width = board[0].size();
        int count = 0;
        for(int i = x - 1; i <= x + 1; i++){
            for(int j = y - 1; j <= y + 1; j++){
                if(i == x && j == y) continue;
                if(i >= 0 && i < height && j >= 0 && j < width && board[i][j] > 0){
                    count++;
                }
            }
        }
        return board[x][y] ? count + 1 : -count;
    }
};