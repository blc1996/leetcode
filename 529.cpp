class Solution {
public:

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board.size() == 0) return board;
        int h = board.size(), w = board[0].size();
        queue<pair<int, int>> q;
        q.push(pair<int, int>(click[0], click[1]));
        while(!q.empty()){
            auto curClick = q.front();
            q.pop();
            if(board[curClick.first][curClick.second] == 'M'){
                board[curClick.first][curClick.second] = 'X';
                return board;
            }
            vector<pair<int, int>> neighbors = getNeighbors(h, w, curClick);
            int mineCount = 0;
            for(auto p : neighbors){
                if(board[p.first][p.second] == 'M'){
                    mineCount++;
                }
            }
            if(mineCount == 0){
                board[curClick.first][curClick.second] = 'B';
                for(auto p : neighbors){
                    if(board[p.first][p.second] == 'E'){
                        board[p.first][p.second] = 'B';
                        q.push(p);
                    }
                }
            }else{
                board[curClick.first][curClick.second] = mineCount + '0';
            }
        }
        return board;
    }

    vector<pair<int, int>> getNeighbors(int h, int w, const pair<int, int>& click){
        vector<pair<int, int>> res;
        int x = click.first, y = click.second;
        if(x > 0 && y > 0) res.push_back(pair<int, int>(x - 1, y - 1));
        if(x > 0) res.push_back(pair<int, int>(x - 1, y));
        if(x > 0 && y < w - 1) res.push_back(pair<int, int>(x - 1, y + 1));
        if(y > 0) res.push_back(pair<int, int>(x, y - 1));
        if(y < w - 1) res.push_back(pair<int, int>(x, y + 1));
        if(x < h - 1 && y > 0) res.push_back(pair<int, int>(x + 1, y - 1));
        if(x < h - 1) res.push_back(pair<int, int>(x + 1, y));
        if(x < h - 1 && y < w - 1) res.push_back(pair<int, int>(x + 1, y + 1));
        return res;
    }
};