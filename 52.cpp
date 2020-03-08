class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<bool> col(n, true);
        vector<bool> leftCross(n*2-1, true);
        vector<bool> rightCross(n*2-1, true);
        solveNQueensCore(n, res, col, leftCross, rightCross);
        return res;
    }
    
    void solveNQueensCore(int remain, int& res, vector<bool>& col, vector<bool>& leftCross, vector<bool>& rightCross){
        if(remain == 0){
            res++;
            return;
        }
        int n = col.size(), index = n - remain;
        for(int i = 0; i < n; i++){
            if(col[i] && leftCross[i+index] && rightCross[n-1+i-index]){
                col[i] = false; leftCross[i+index] = false; rightCross[n-1+i-index] = false;
                solveNQueensCore(remain - 1, res, col, leftCross, rightCross);
                col[i] = true; leftCross[i+index] = true; rightCross[n-1+i-index] = true;
            }
        }
    }
};