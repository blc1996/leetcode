class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;
        int left = 0, right = nums.size() - 1;
        while(nums[left] > nums[right]){
            int idx = (left + right) / 2;
            if(nums[idx] > nums[idx + 1]){
                right = idx;
                break;
            }
            if(nums[idx] > nums[right]){
                left = idx;
            }else{
                right = idx;
            }
        }
        left = (right + 1) % nums.size();
        if(target > nums[nums.size() - 1]){
            left = 0;
        }else{
            right = nums.size() - 1;
        }
        //second binary search
        while(left <= right){
            int idx = (left + right) / 2;
            if(nums[idx] == target){
                return idx;
            }else if(nums[idx] > target)
                right = idx - 1;
            else
                left = idx + 1;
        }
        return -1;
    }
};
