class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> output;
        for(int i = 0; i < numRows; i++){
            vector<int> temp(i + 1, 1);
            temp[0] = 1;
            temp[temp.size() - 1] = 1;
            for(int j = 1; j < i; j++){
                temp[j] = output[i - 1][j - 1] + output[i - 1][j];
            }
            output.push_back(temp);
        }
        return output;
    }
};
