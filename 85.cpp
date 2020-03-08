class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        int height = matrix.size(), width = matrix[0].size();
        vector<int> verticalLength(width + 1, 0);
        vector<vector<int>> horizontalLength(height, vector<int>(width + 1, 0));
        int res = 0;
        for(int i = 0; i < height; i++){
            vector<int> newVerticalLength(width + 1, 0);
            for(int j = 0; j < width; j++){
                if(matrix[i][j] == '1'){
                    verticalLength[j + 1]++;
                    horizontalLength[i][j + 1] = 1 + horizontalLength[i][j];
                    int idx = i, tempWidth = INT_MAX;
                    while(i - idx < verticalLength[j + 1]){
                        tempWidth = min(tempWidth,  horizontalLength[idx][j + 1]);
                        res = max(res, tempWidth * (i - idx + 1));
                        idx--;
                    }
                }else{
                    verticalLength[j + 1] = 0;
                }
            }
        }
        return res;
    }
};