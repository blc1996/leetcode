class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> s;
        for(unsigned i = 0; i < nums.size(); i++){
            long n = nums[i];
            if(i > k)
                s.erase(nums[i-k-1]);

            auto it = s.lower_bound(n - t);
            if( it != s.end() && *it - nums[i] <= t)
                return true;
            s.insert(nums[i]);
        }
        return false;
    }
};
