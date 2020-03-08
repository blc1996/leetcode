class Solution {
public:
    int findDist(vector<vector<int>>& distance, vector<vector<int>>& matrix, int x, int y){
        if(matrix[x][y] == 0){
            distance[x][y] = 0;
            return 0;
        }
        if(distance[x][y] != -1){
            return distance[x][y];
        }
        if(distance[x][y] == -1) distance[x][y] = INT_MAX - 1;
        int minDist = x > 0 ? findDist(distance, matrix, x - 1, y) : distance[x][y];
        if(y > 0) minDist = min(minDist, findDist(distance, matrix, x, y - 1));
        if(x < matrix.size() - 1) minDist = min(minDist, findDist(distance, matrix, x + 1, y));
        if(y < matrix[0].size() - 1) minDist = min(minDist, findDist(distance, matrix, x, y + 1));
        distance[x][y] = minDist + 1;
        return distance[x][y];
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return vector<vector<int>>();
        int height = matrix.size(), width = matrix[0].size();
        vector<vector<int>> dist(height, vector<int>(width, -1));
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                findDist(dist, matrix, i, j);
            }
        }
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                findDist(dist, matrix, i, j);
            }
        }
        return dist;
    }
};