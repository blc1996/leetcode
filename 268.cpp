class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long sum = 0;
        for(int i : nums){
            sum += i;
        }
        return (nums.size() * (nums.size() + 1) / 2) - sum;
    }
};
