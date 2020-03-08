class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        set<int> st;
        int res = 0, midInteger = INT_MIN;
        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[i] < midInteger) return true;
            res = 0;
            for_each(st.upper_bound(nums[i]), st.end(), [&res](auto x){res++;});
            if(res >= 1){
                // cout<<i<<" "<<nums[i]<<endl;
                midInteger = max(midInteger, nums[i]);
            }
            st.insert(nums[i]);
        }
        return false;
    }
};

class Solution {
public:
    /*
    [3 1 4 2 5 9]
    S1 1
    S2 1 2
    S3 1 2 5
    */
    
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        
        int S1 = INT_MIN;
        int S2 = INT_MIN;
        int S3 = INT_MIN;
        bool res = false;
        S1 = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= S1) {
                S1 = nums[i];
            } else if (S2 == INT_MIN || (nums[i] > S1 && nums[i] <= S2)) {
                S2 = nums[i];
            } else if (S3 == INT_MIN || (nums[i] > S2 && nums[i] <= S3)) {
                S3 = nums[i];
            }
        }
        
        return S3 != INT_MIN;
    }
};