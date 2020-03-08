class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int prev = 0, cur = 0;
        int res = 0;
        for(int i = 0; i < n; i++){
            prev = 0, cur = 0;
            for(int j = 1; i + j <= n; j++){
                cur = nums[i + j - 1] + prev;
                if(cur == k) res++;
                prev = cur;
            }
        }
        return res;
    }
};

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> store(n + 1, 0);
        for(int j = 1; j <= n; j++){
            store[j] = nums[j - 1] + store[j - 1];
        }
        // perform sth like two-sum
        unordered_map<int, int> mp;
        int res = 0;
        for(int i = 0; i <= n; i++){
            if(mp.count(store[i] - k)){
                res += mp[store[i] - k];
            }
            mp[store[i]]++;
        }
        return res;
    }
};


