class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0)
            return vector<string>();
        nums.push_back(INT_MIN);
        vector<string> output;
        int initial = nums[0];
        for(unsigned i = 1; i < nums.size(); i++){
            if((long)nums[i] - (long)nums[i-1] != 1){
                if(initial == nums[i-1]){
                    output.push_back(to_string(initial));
                    initial = nums[i];
                }else{
                    output.push_back(to_string(initial) + "->" + to_string(nums[i-1]));
                    initial = nums[i];
                }
            }
        }
        return output;
    }
};
