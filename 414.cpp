class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long max1 = nums[0];
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > max1){
                max1 = nums[i];
            }
        }
        long max2 = LONG_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > max2 && nums[i] < max1){
                max2 = nums[i];
            }
        }
        long max3 = LONG_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > max3 && nums[i] < max2){
                max3 = nums[i];
            }
        }
        return max3 == LONG_MIN ? max1 : max3;
    }
};
