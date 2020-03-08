class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.size() == 0){
            return S == 0 ? 1 : 0;
        }
        int temp = nums.back();
        nums.pop_back();
        int res = findTargetSumWays(nums, S + temp) + findTargetSumWays(nums, S - temp);
        nums.push_back(temp);
        return res;
    }
};


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        unordered_map<int, int> mp, tempMp;
        mp.insert({0, 1});
        for(int i = 0; i < nums.size(); i++){
            for(auto it = mp.begin(); it != mp.end(); it++){
                tempMp[it->first + nums[i]] += it->second;
                tempMp[it->first - nums[i]] += it->second;
            }
            mp = tempMp;
            tempMp.clear();
        }
        return mp[S];
    }
};


                sum(P) - sum(N) = target
sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)
                       2 * sum(P) = target + sum(nums)
So the original problem has been converted to a subset sum problem as follows:
Find a subset P of nums such that sum(P) = (target + sum(nums)) / 2