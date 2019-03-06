class Solution {
public:
    unordered_set<pair<int, int>> set;

    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.size() == 0)
            return vector<pair<int, int>>();
        vector<pair<int, int>> output;
        for(int i = 0; i < matrix.size(); i ++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(helper(matrix, i, j, false, 0) && helper(matrix, i, j, true, 0)){
                    output.push_back(pair<int, int>(i, j));
                }
            }
        }
        return output;
    }

    bool helper(vector<vector<int>>& matrix, int y, int x, bool flag, int direction){
        if(set.count(pair<int, int>(y, x))){
            return false;
        }else{
            set.insert(pair<int, int>(y, x));
        }
        if(flag){
            if(y == matrix.size() - 1 || x == matrix[0].size()){
                return true;
            }
            bool result = false;
            if(y > 0 && matrix[y][x] >= matrix[y-1][x]){
                result = result || helper(matrix, y - 1, x, true);
            }
            if(x < 0 && matrix[y][x] >= matrix[y][x-1]){
                result = result || helper(matrix, y, x - 1, true);
            }
            if(matrix[y][x] >= matrix[y+1][x]){
                result = result || helper(matrix, y + 1, x, true);
            }
            if(matrix[y][x] >= matrix[y][x+1]){
                result = result || helper(matrix, y, x + 1, true);
            }
            return result;
        }else{
            if(y == 0 || x == 0){
                return true;
            }
            bool result = false;
            if(y < matrix.size() - 1  && matrix[y][x] >= matrix[y+1][x]){
                result = result || helper(matrix, y + 1, x, false);
            }
            if(x < matrix[0].size() - 1  && matrix[y][x] >= matrix[y][x+1]){
                result = result || helper(matrix, y, x + 1, false);
            }
            if(matrix[y][x] >= matrix[y-1][x]){
                result = result || helper(matrix, y - 1, x, false);
            }
            if(matrix[y][x] >= matrix[y][x-1]){
                result = result || helper(matrix, y, x - 1, false);
            }
            return result;
        }
    }
};
