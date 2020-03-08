class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long sum = 0, n = nums.size();
        for(int i : nums){
            sum += i;
        }
        sort(nums.begin(), nums.end());
        int med = nums[nums.size() / 2];
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            res += abs(nums[i] - med);
        }
        return res;
    }
};