class Solution {
public:
    vector<vector<int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int findMaxArea(vector<vector<int>>& grid, int originX, int originY){
        int maxX = grid.size(), maxY = grid[0].size();
        queue<pair<int, int>> q;
        q.push(pair<int, int>(originX, originY));
        grid[originX][originY] = 0;
        int area = 0;
        while(!q.empty()){
            auto curPoint = q.front();
            q.pop();
            area++;
            for(auto m : moves){
                int newX = curPoint.first + m[0];
                int newY = curPoint.second + m[1];
                if(newX >= 0 && newY >= 0 && newX < maxX && newY < maxY && grid[newX][newY] == 1){
                    q.push(pair<int, int>(newX, newY));
                    grid[newX][newY] = 0;
                }
            }
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0;
        int res = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]){
                    int temp = findMaxArea(grid, i, j);
                    res = max(res, temp);
                    // cout<<temp<<endl;
                }
            }
        }
        return res;
    }
};