class Solution {
public:
    vector<vector<int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void findShortestPath(vector<vector<int>>& grid, vector<vector<int>>& countStore, vector<vector<int>>& indexCount, int originX, int originY, int index){
        int maxX = grid.size(), maxY = grid[0].size();
        unordered_map<int, int> visited;
        queue<pair<int, int>> q;
        q.push(pair<int, int>(originX, originY));
        visited.insert({originX * maxY + originY, 0});
        while(!q.empty()){
            auto curPoint = q.front();
            q.pop();
            int curStepCount = visited[curPoint.first * maxY + curPoint.second];
            countStore[curPoint.first][curPoint.second] += curStepCount;
            indexCount[curPoint.first][curPoint.second]++;
            // cout<<"count"<<countStore[curPoint.first][curPoint.second]<<endl;
            for(auto m : moves){
                int newX = curPoint.first + m[0];
                int newY = curPoint.second + m[1];
                if(newX >= 0 && newY >= 0 && newX < maxX && newY < maxY && grid[newX][newY] == 0 &&
                        !visited.count(newX * maxY + newY) && indexCount[newX][newY] >= index){
                    q.push(pair<int, int>(newX, newY));
                    visited.insert({newX * maxY + newY, curStepCount + 1});
                }
            }
        }
    }

    int shortestDistance(vector<vector<int>>& grid) {
        vector<pair<int, int>> buildings;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    buildings.push_back(pair<int, int>(i, j));
                }
            }
        }
        vector<vector<int>> store(grid.size(), vector<int>(grid[0].size(), 0));
        vector<vector<int>> indexCount(grid.size(), vector<int>(grid[0].size(), 0));

        for(int k = 0; k < buildings.size(); k++){
            auto b = buildings[k];
            findShortestPath(grid, store, indexCount, b.first, b.second, k);
        }

        int res = -1;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0){
                    int tempRes = 0;
                    if(indexCount[i][j] == buildings.size()){
                        tempRes = store[i][j];
                    }else{
                        tempRes = -1;
                    }
                    // cout<<tempRes<<" ";
                    res = tempRes == -1 ? res : res == -1 ? tempRes : min(res, tempRes);
                }
            }
            // cout<<endl;
        }
        return res;
    }
};




class Solution {
public:
    vector<vector<int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int findShortestPath(vector<vector<int>>& grid, int originX, int originY, int destX, int destY){
        int maxX = grid.size(), maxY = grid[0].size();
        unordered_map<int, int> visited;
        queue<pair<int, int>> q;
        q.push(pair<int, int>(originX, originY));
        visited.insert({originX * maxY + originY, 0});
        while(!q.empty()){
            auto curPoint = q.front();
            q.pop();
            int curStepCount = visited[curPoint.first * maxY + curPoint.second];
            for(auto m : moves){
                int newX = curPoint.first + m[0];
                int newY = curPoint.second + m[1];
                if(newX >= 0 && newY >= 0 && newX < maxX && newY < maxY && !visited.count(newX * maxY + newY)){
                    if(grid[newX][newY] == 0){
                        q.push(pair<int, int>(newX, newY));
                        visited.insert({newX * maxY + newY, curStepCount + 1});
                    }else if(grid[newX][newY] == 1 && newX == destX && newY == destY){
                        // cout<<"return"<<newX<<" "<<newY<<" "<<curStepCount+1<<endl;
                        return curStepCount + 1;
                    }
                }
            }
        }
        return -1;
    }

    int shortestDistance(vector<vector<int>>& grid) {
        vector<pair<int, int>> buildings;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    buildings.push_back(pair<int, int>(i, j));
                }
            }
        }
        int res = -1;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0){
                    int tempRes = 0;
                    for(auto b : buildings){
                        int pathVal = findShortestPath(grid, i, j, b.first, b.second);
                        if(pathVal == -1){
                            tempRes = -1;
                            break;
                        }else{
                            tempRes += pathVal;
                        }
                    }
                    // cout<<tempRes<<" ";
                    res = tempRes == -1 ? res : res == -1 ? tempRes : min(res, tempRes);
                }
            }
            // cout<<endl;
        }
        return res;
    }
};