class Solution {
public:
    map<pair<int, int>, int> mp;

    int getMoneyAmount(int n) {
        return helper(1, n);
    }

    int helper(int lower, int higher){
        if(lower >= higher)
            return 0;
        if(higher - lower == 1)
            return lower;
        if(mp.count(pair<int, int>(higher, lower))){
            return mp[pair<int, int>(higher, lower)];
        }
        int current = INT_MAX;
        for(int i = 1; i < higher - lower; i++){
            int temp = higher - i;
            temp = temp + max(helper(lower, temp - 1), helper(temp + 1, higher));
            current = temp < current ? temp : current;
        }
        mp.insert({pair<int, int>(higher, lower), current});
        return current;
    }
};// recuresive is too slow, must use dp

class Solution {
public:
    // map<pair<int, int>, int> mp;
    vector<vector<int>> dp;

    int getMoneyAmount(int n) {
        dp = vector<vector<int>>(n+1, vector<int>(n+1, 0));
        return helper(1, n);
    }

    int helper(int lower, int higher){
        if(lower >= higher)
            return 0;
        if(higher - lower == 1)
            return lower;
        if(dp[lower][higher]){
            return dp[lower][higher];
        }
        int current = INT_MAX;
        for(int i = 1; i < higher - lower; i++){
            int temp = higher - i;
            temp = temp + max(helper(lower, temp - 1), helper(temp + 1, higher));
            current = temp < current ? temp : current;
        }
        dp[lower][higher] = current;
        return current;
    }
};
