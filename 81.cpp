class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return false;
        int left = 0, right = nums.size() - 1;
        while(left + 1 < nums.size() && nums[left] == nums[left + 1])
            left++;
        while(right - 1 >= 0 && nums[right] == nums[right - 1])
            right--;
        if(nums[left] == nums[right] && left < right){
            right--;
        }
        while(nums[left] > nums[right]){
            while(left + 1 < nums.size() && nums[left] == nums[left + 1])
                left++;
            while(right - 1 >= 0 && nums[right] == nums[right - 1])
                right--;
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
        while(right + 1 < nums.size() && nums[right] == nums[right + 1])
            right++;
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
                return true;
            }else if(nums[idx] > target)
                right = idx - 1;
            else
                left = idx + 1;
        }
        return false;
    }
};


class Solution {
public:

    bool search(vector<int>& nums, int target) {
        if(!nums.size()) return false;

        int left = 0;
        int right = nums.size() - 1;

        if(nums[left] == target || nums[right] == target) return true;

        while(left <= right) {
            int mid = (left + right) >> 1;

            if(nums[mid] == target) return true;

            if(nums[left] <= target && nums[mid] > target) { // this would be a normal situation...
                right = mid - 1;
            } else if(nums[right] >= target && nums[mid] < target) {
                left = mid + 1;
            } else if(nums[right] >= target && nums[mid] > target){
                left++;
            } else {
                right--;
            }
        }

        return false;
    }
};
