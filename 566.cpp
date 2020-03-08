class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if(nums.size() == 0 || r * c != nums.size() * nums[0].size()){
            return nums;
        }
        vector<vector<int>> output(r, vector<int>(c, 0));
        int row = 0, count = 0;
        for(auto i : nums){
            for(int j : i){
                if(count >= c){
                    count = 0;
                    row++;
                }
                output[row][count++] = j;
            }
        }
        return output;
    }
};

