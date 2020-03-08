class Solution {
public:
    int state[1 << 20] = {0};

    bool PredictTheWinner(vector<int>& nums) {
        return predictCore(0, nums.size() - 1, 0, true, nums) >= 0 ? true : false;
    }

    int predictCore(int left, int right, int k, bool side, vector<int>& nums){
        if(state[k]){
            return state[k];
        }else if(left == right){
            if(side){
                return state[k | 1 << left] = nums[left];
            }else{
                return state[k | 1 << left] = -nums[left];
            }
        }
        
        predictCore(left + 1, right, k | 1 << left, !side, nums);
        predictCore(left, right - 1, k | 1 << right, !side, nums);
        if(side)
            return state[k] = max(nums[left] + state[k | 1 << left], nums[right] + state[k | 1 << right]);
        else
            return state[k] = min(state[k | 1 << left] - nums[left], state[k | 1 << right] - nums[right]);
    }
};