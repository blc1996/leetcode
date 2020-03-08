class Solution {
public:
    int minMoves(vector<int>& nums) {
        long sum = 0, n = nums.size();
        for(int i : nums){
            sum += i;
        }
        int min = *min_element(nums.begin(), nums.end());
        return sum - min * n;
    }
};