class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0) return 0;
        unordered_map<int, int> mp;
        for(int i : nums){
            mp[i]++;
        }
        int res = 0;
        for(int i : nums){
            if(k != 0 && mp.count(i)){
                if(mp.count(i + k)) res++;
                if(mp.count(i - k)) res++;
                mp.erase(i);
            }else if(mp.count(i) && mp[i] > 1){
                res++;
                mp.erase(i);
            }
        }
        return res;
    }
};