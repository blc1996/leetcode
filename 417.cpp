class Solution {
public:
    struct pair_hash
    {
        template <class T1, class T2>
        std::size_t operator () (std::pair<T1, T2> const &pair) const
        {
            std::size_t h1 = std::hash<T1>()(pair.first);
            std::size_t h2 = std::hash<T2>()(pair.second);

            return h1 ^ h2;
        }
    };
    unordered_set<pair<int, int>, pair_hash> set;
    vector<vector<int>> dp;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.size() == 0)
            return vector<vector<int>>();
        vector<vector<int>> output;
        dp = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(helper(matrix, i, j, 0) && helper(matrix, i, j, 1)){
                    output.push_back(vector<int>({i, j}));
                }
            }
        }
        return output;
    }

    bool helper(vector<vector<int>>& matrix, int y, int x, int flag){
        if(dp[y][x] & 1 << flag){
            return true;
        }else if(dp[y][x] & 1 << (flag + 2)){
            return false;
        }

        if(set.count(pair<int, int>(y, x))){
            return false;
        }else{
            set.insert(pair<int, int>(y, x));
        }
        if(flag){
            if(y == matrix.size() - 1 || x == matrix[0].size() - 1){
                set.erase(pair<int, int>(y, x));
                dp[y][x] |= 1 << flag;
                return true;
            }
            bool result = false;
            if(y > 0 && matrix[y][x] >= matrix[y-1][x]){
                result = result || helper(matrix, y - 1, x, 1);
            }
            if(x > 0 && matrix[y][x] >= matrix[y][x-1]){
                result = result || helper(matrix, y, x - 1, 1);
            }
            if(matrix[y][x] >= matrix[y+1][x]){
                result = result || helper(matrix, y + 1, x, 1);
            }
            if(matrix[y][x] >= matrix[y][x+1]){
                result = result || helper(matrix, y, x + 1, 1);
            }
            set.erase(pair<int, int>(y, x));
            if(result) dp[y][x] |= 1 << flag;
            else dp[y][x] |= 1 << (flag + 2);
            return result;
        }else{
            if(y == 0 || x == 0){
                set.erase(pair<int, int>(y, x));
                dp[y][x] |= 1 << flag;
                return true;
            }
            bool result = false;
            if(y < matrix.size() - 1  && matrix[y][x] >= matrix[y+1][x]){
                result = result || helper(matrix, y + 1, x, 0);
            }
            if(x < matrix[0].size() - 1  && matrix[y][x] >= matrix[y][x+1]){
                result = result || helper(matrix, y, x + 1, 0);
            }
            if(matrix[y][x] >= matrix[y-1][x]){
                result = result || helper(matrix, y - 1, x, 0);
            }
            if(matrix[y][x] >= matrix[y][x-1]){
                result = result || helper(matrix, y, x - 1, 0);
            }
            set.erase(pair<int, int>(y, x));
            if(result) dp[y][x] |= 1 << flag;
            else dp[y][x] |= 1 << (flag + 2);
            return result;
        }
    }
};