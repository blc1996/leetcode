class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int index = 0, length = nums.size();
        while(index < length){
            if(nums[index] == index + 1 || nums[index] == nums[nums[index] - 1]){
                index++;
            }else{
                swap(nums[index], nums[nums[index] - 1]);
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(i + 1 != nums[i]){
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};