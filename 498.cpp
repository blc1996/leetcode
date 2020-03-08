class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        bool upFlag = true;
        int x = 0, y = 0;
        vector<int> res;
        while(x < matrix.size() && y < matrix[0].size()){
            if(upFlag){
                res.push_back(matrix[x][y]);
                if(x == 0 || y == matrix[0].size() - 1){
                    upFlag = !upFlag;
                    if(y != matrix[0].size() - 1){
                        y++;
                    }else{
                        x++;
                    }
                }else{
                    x--; y++;
                }
            }else{
                res.push_back(matrix[x][y]);
                if(y == 0 || x == matrix.size() - 1){
                    upFlag = !upFlag;
                    if(x != matrix.size() - 1){
                        x++;
                    }else{
                        y++;
                    }
                }else{
                    x++; y--;
                }
            }
        }
        return res;
    }
};