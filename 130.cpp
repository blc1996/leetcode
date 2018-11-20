class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0)
            return;
        vector<int> a(board.size()*board[0].size(), -1);

        for(unsigned i = 0; i < board.size(); i++){
            for(unsigned j = 0; j < board[0].size(); j++){
                if(board[i][j] == 'O'){
                    if(j > 0 && board[i][j-1] == 'O'){
                        dUnion(i * board[0].size() + j, i * board[0].size() + j - 1, a);
                    }
                    if(i > 0 && board[i - 1][j] == 'O'){
                        dUnion(i * board[0].size() + j, (i-1) * board[0].size() + j, a);
                    }
                }
            }
        }

        for(unsigned i = 0; i < board.size(); i++){
            if(board[i][0] == 'O')
                a[find(i*board[0].size(), a)] = -2;
                a[find(i*board[0].size() + board[0].size() - 1, a)] = -2;
        }

        for(unsigned j = 0; j < board[0].size(); j++){
            if(board[0][j] == 'O')
                a[find(j, a)] = -2;
                a[find((board.size() - 1)*board[0].size() + j, a)] = -2;
        }

        for(unsigned i = 0; i < board.size(); i++){
            for(unsigned j = 0; j < board[0].size(); j++){
                if(board[i][j] == 'O'){
                    if(a[find(i*board[0].size() + j, a)] == -1)
                        board[i][j] = 'X';
                }
            }
        }
    }


    int find(int x, std::vector<int>& parents) {
       // your code
       while(parents[x]  >= 0)
            x = parents[x];
       return x;
    }

    void dUnion(int a, int b, vector<int>& dSet){
        a = find(a, dSet);
        b = find(b, dSet);
        if(a == b)
            return;
        else
            dSet[b] = a;
    }
};



class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0)
            return;

        for(unsigned i = 0; i < board.size(); i++){
            if(board[i][0] == 'O')
                check(i, 0, board);
            if(board[i][board[0].size() - 1] == 'O')
                check(i, board[0].size() - 1, board);
        }
        for(unsigned i = 0; i < board[0].size(); i++){
            if(board[0][i] == 'O')
                check(0, i, board);
            if(board[board.size() - 1][i] == 'O')
                check(board.size() - 1, i, board);
        }

        for(unsigned i = 0; i < board.size(); i++){
            for(unsigned j = 0; j < board[0].size(); j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == '1')
                    board[i][j] = 'O';
            }
        }
    }

    void check(int i, int j, vector<vector<char>>& board){
        board[i][j] = '1';

        if(i > 0 && board[i-1][j] == 'O')
            check(i - 1, j, board);

        if(j > 0 && board[i][j - 1] == 'O')
            check(i, j - 1, board);

        if(i < board.size() - 1 && board[i+1][j] == 'O')
            check(i + 1, j, board);

        if(j < board[0].size() - 1 && board[i][j + 1] == 'O')
            check(i, j + 1, board);
    }
};
