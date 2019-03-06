class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        vector<int> candidates;
        int maxbit = -1;
        for(int i = 0; i < nums.size(); i++){
            int temp = findMaxBit(nums[i]);
            if(temp > maxbit){
                nums.clear();
                maxbit = temp;
                candidates.push_back(i);
            }else if(temp == maxbit){
                candidates.push_back(i);
            }
        }
        int maxVal = 0;
        for(int i = 0; i < candidates.size(); i++){
            int number = nums[candidates[i]];
            for(int j = 0; j < nums.size(); j++){
                maxVal = maxVal > number ^ candidates[j] ? maxVal : number ^ candidates[j];
            }
        }
        return maxVal;
    }

    int findMaxBit(int num){
        for(int i = 31; i >= 0; i++){
            if(((num >> i) & 1) == 1){
                return i;
            }
        }
        return -1;
    }
};
