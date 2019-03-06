class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        vector<vector<int>> output(r, vector<int>(c, 0));
        // for(int i = 0; i < nums.size(); i++){
        //     for()
        // }
        int row = 0, count = 0;
        for(auto i : nums){
            for(int j : i){
                if(count >= c){
                    count = 0;
                    row++;
                }
                output[row][count++];
            }
        }
        return output;
    }
};
