class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long value = 1;
        long minusMax = 0, maxVal = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                value *= nums[i];
                if(value > 0){
                    maxVal = max(maxVal, value);
                }else{
                    if(minusMax == 0){
                        minusMax = value;
                        maxVal = max(maxVal, value);
                    }else{
                        maxVal = max(maxVal, value / minusMax);
                        minusMax = max(minusMax, value);
                    }
                }
            }else{
                maxVal = max(maxVal, 0L);
                value = 1;
                minusMax = 0;
            }
        }
        return maxVal;
    }
};