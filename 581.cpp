class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        priority_queue<int, std::vector<int>, greater<int>> sm;
        priority_queue<int> gt;
        for(int i : nums){
            sm.push(i);
            gt.push(i);
        }
        int left = 0, right = nums.size() - 1;
        if(nums[left] == sm.top()){
            sm.pop();
            left++;
        }
        if(right >= left && nums[right] == gt.top()){
            gt.pop();
            right--;
        }
        return right - left + 1;
    }
};