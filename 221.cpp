class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        vector<vector<int>> board(matrix.size(), vector<int>(matrix[0].size(), 0));
        int maxsize = 0;
        for(unsigned i = 0; i < matrix.size(); i++){
            board[i][0] = matrix[i][0] - '0';
            maxsize = max(board[i][0], maxsize);
        }
        for(unsigned i = 0; i < matrix[0].size(); i++){
            board[0][i] = matrix[0][i]  - '0';
            maxsize = max(board[0][i], maxsize);
        }
        for(unsigned i = 1; i < matrix.size(); i++){
            for(unsigned j = 1; j < matrix[0].size(); j++){
                if(matrix[i][j] == '0'){
                    board[i][j] = 0;
                }else{
                    board[i][j] = min(min(board[i-1][j], board[i][j-1]), board[i-1][j-1]) + 1;
                }
                maxsize = max(maxsize, board[i][j]);
            }
        }
        return maxsize*maxsize;
    }
};


//optimize space complexity
//no need to maintain the whole board
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        int width = matrix[0].size(), maxsize = 0;
        vector<int> *row1 = new vector<int>(width, 0);
        vector<int> *row2 = new vector<int>(width, 0);
        for(unsigned i = 0; i < width; i++){
            row1->at(i) = matrix[0][i] - '0';
            maxsize = max(maxsize, row1->at(i));
        }
        for(unsigned i = 1; i < matrix.size(); i++){
            for(unsigned j = 0; j < width; j++){
                if(j == 0){
                    row2->at(0) = matrix[i][0];
                }else{
                    if(matrix[i][j] == '0'){
                        row2->at(j) = 0;
                    }else{
                        row2->at(j) = min(min(row2->at(j-1), row1->at(j)), row1->at(j-1)) + 1;
                    }
                }
                maxsize = max(maxsize, row2->at(j));
            }
            vector<int> *temp = row2;
            row2 = row1;
            row1 = temp;
        }
        delete[] row1;
        delete[] row2;
        return maxsize*maxsize;
    }
};
