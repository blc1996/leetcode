class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = nums[fast];
        slow = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};
