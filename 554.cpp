class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> mp;
        int sum, n = wall.size();
        for(int i = 0; i < n; i++){
            sum = 0;
            for(int j = 0; j < wall[i].size() - 1; j++){
                sum += wall[i][j];
                mp[sum]++;
            }
        }
        int res = INT_MAX;
        for(auto it = mp.begin(); it != mp.end(); it++){
            res = min(res, n - it->second);
        }
        return res == INT_MAX ? n : res;
    }
};