class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if(nums.size() == 0){
            return false;
        }
        int sum = 0;
        for(int i : nums){
            sum += i;
        }
        int l = sum / 4;
        if(l * 4 != sum){
            return false;
        }
        sort(nums.begin(), nums.end());
        return makesqureCore(nums, nums.size() - 1, l, l, l, l);
    }

    bool makesqureCore(vector<int>& nums, int index, int a, int b, int c, int d){
        if(index < 0){
            return true;
        }
        if(a >= nums[index] && makesqureCore(nums, index - 1, a - nums[index], b, c, d)){
            return true;
        }
        if(b >= nums[index] && makesqureCore(nums, index - 1, a, b - nums[index], c, d)){
            return true;
        }
        if(c >= nums[index] && makesqureCore(nums, index - 1, a, b, c - nums[index], d)){
            return true;
        }
        if(d >= nums[index] && makesqureCore(nums, index - 1, a, b, c, d - nums[index])){
            return true;
        }
        return false;
    }
};