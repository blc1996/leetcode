class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        int maxVal = 0;
        vector<int> stepMax(nums.size(), 0);
        dfs(nums, 2, 2, 0, maxVal, stepMax);
        dfs(nums, 1, 1, 0, maxVal, stepMax);
        dfs(nums, 0, 0, 0, maxVal, stepMax);
        return maxVal;
    }

    void dfs(vector<int>& nums, int index, int start, int sum, int& maxVal, vector<int>& stepMax){
        if(index >= nums.size() || (index + 1) % nums.size() == start){
            return;
        }
        int newsum = sum + nums[index];
        if(stepMax[index] >= newsum)
            return;
        else
            stepMax[index] = newsum;
        maxVal = max(maxVal, newsum);
        dfs(nums, index + 2, start, newsum, maxVal, stepMax);
        dfs(nums, index + 3, start, newsum, maxVal, stepMax);
    }
};


class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        
        return maxVal;
    }
};