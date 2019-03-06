class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if(board.size() == 0 || board[0].size() == 0){
            return 0;
        }
        int count = 0;
        for(int i = 0; i < board.size(); i++){
            if(board[i][0] == 'X'){
                count++;
                if(i > 0 && board[i-1][0] == 'X')
                    count--;
            }
            for(int j = 1; j < board[i].size(); j++){
                if(board[i][j] == 'X' && board[i][j-1] != 'X'){
                    count++;
                    if(i > 0 && board[i-1][j] == 'X')
                        count--;
                }
            }
        }
        return count;
    }
};

