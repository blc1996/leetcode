class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int x = 0, y = 0;
        while(x < matrix.size() - 1 && y < matrix[0].size() - 1 && matrix[x][y] < target){
            x++; y++;
        }
        int temp1 = x, temp2 = y;
        while(x >= 0 && y < matrix[0].size()){
            if(matrix[x][y] == target)
                return true;
            else if(matrix[x][y] > target)
                x--;
            else
                y++;
        }
        x = temp1, y = temp2;
        while(x < matrix.size() && y >= 0){
            if(matrix[x][y] == target)
                return true;
            else if(matrix[x][y] > target)
                y--;
            else
                x++;
        }

    }
};
