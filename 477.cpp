class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> sum(32, 0);
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < 32; j++){
                if(nums[i] & 1 << j){
                    res += i - sum[j];
                    sum[j]++;
                }else{
                    res += sum[j];
                }
            }
        }
        return res;
    }
};