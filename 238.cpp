class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> a1(nums.size(), 1), a2(nums.size(), 1);
        for(unsigned i = 1; i < nums.size(); i++){
            a1[i] = a1[i - 1] * nums[i - 1];
            a2[nums.size() - 1 - i] = a2[nums.size() - i] * nums[nums.size() - i];
        }
        vector<int> output;
        for(unsigned i = 0; i < nums.size(); i++){
            output.push_back(a1[i] * a2[num.size() - i]);
        }
        return output;
    }
};
