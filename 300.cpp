class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        vector<int> array;
        array.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > array[array.size() - 1]){
                array.push_back(nums[i]);
            }else{
                int left = 0, right = array.size() - 1;
                while(left < right){
                    int index = left + (right - left)/2;
                    if(array[index] > nums[i]){
                        right = index;
                    }else if(array[index] == nums[i]){
                        left = index;
                        right = index;
                    }else{
                        left = index + 1;
                    }
                }
                array[left] = nums[i];
            }
        }
        return array.size();
    }
};
