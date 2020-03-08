class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        string tempRow(n, '.');
        vector<string> tempBoard(n, tempRow);
        vector<bool> col(n, true);
        vector<bool> leftCross(n*2-1, true);
        vector<bool> rightCross(n*2-1, true);
        solveNQueensCore(n, res, tempBoard, col, leftCross, rightCross);
        return res;
    }

    void solveNQueensCore(int remain, vector<vector<string>>& res, vector<string>& tempBoard, 
                        vector<bool>& col, vector<bool>& leftCross, vector<bool>& rightCross){
        if(remain == 0){
            res.push_back(tempBoard);
            return;
        }
        int n = col.size(), index = n - remain;
        for(int i = 0; i < n; i++){
            if(col[i] && leftCross[i+index] && rightCross[n-1+i-index]){
                tempBoard[index][i] = 'Q';
                col[i] = false; leftCross[i+index] = false; rightCross[n-1+i-index] = false;
                solveNQueensCore(remain - 1, res, tempBoard, col, leftCross, rightCross);
                tempBoard[n - remain][i] = '.';
                col[i] = true; leftCross[i+index] = true; rightCross[n-1+i-index] = true;
            }
        }
    }
};