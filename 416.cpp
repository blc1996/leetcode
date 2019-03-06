class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 == 1){
            return false;
        }
        int target = sum / 2;
        unordered_set<int> set;
        for(int i : nums){
            if(set.count(target)){
                return true;
            }
            for(int j : set){
                set.insert(i + j);
            }
            set.insert(i);
        }
        if(set.count(target)){
            return true;
        }else{
            return false;
        }
    }
};
