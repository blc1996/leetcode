class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<long long> dp(target + 1, 0), newDp(target + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < d; i++){
            for(int j = 0; j <= target; j++){
                if(dp[j]){
                    for(int k = 1; k <= f; k++){
                        if(j + k <= target){
                            newDp[j + k] = (newDp[j + k] + dp[j]) % 1000000007;
                        } 
                    }
                }
            }
            dp = newDp;
            newDp = vector<long long>(target + 1, 0);
        }
        return dp.back();
    }
};