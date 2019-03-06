class Solution {
public:
    int search(vector<int>& nums, int target) {
        // first binary search for the dividing index
        int left = 0, right = nums.size() - 1, idx = 0;
        while(left < right){
            int mid = left + (right - left)/2;
            if(nums[mid] > nums[mid+1]){
                idx = mid + 1;
                break
            }else if(nums[mid] > num[right]){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        left = idx, right = (nums.size() - 1 + idx) % nums.size();
        while(left != right){
            int mid = ((right + nums.size() - idx) % nums.size())/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                right = mid;
            else
                left = (mid + 1) % nums.size();
        }
        if(nums[left] == target)
            return left;
        else
            return -1;
    }
};
