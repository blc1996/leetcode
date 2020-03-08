class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            int left = i + 1, right = nums.size() - 1, upplerLimit = target - nums[i];
            while(left < right){
                if(nums[left] + nums[right] < upplerLimit){
                    res += right - left;
                    left++;
                }else{
                    right--;
                }
            }
        }
        return res;
    }
};