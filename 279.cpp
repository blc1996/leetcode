class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, -1);
        for(int i = 1; i * i <= n; i++){
            dp[i*i] = 1;
        }
        dp[0] = 0;
        return helper(dp, n);
    }

    int helper(vector<int>& dp, int index){
        if(dp[index] != -1)
            return dp[index];
        int i = 1, minVal = index;
        while(i*i < index){
            minVal = min(minVal, helper(dp, i*i) + helper(dp, index - i*i));
            // cout<<index<<"  "<<i*i<<": "<<minVal<<endl;
            i++;
        }
        dp[index] = minVal;
        return minVal;
    }
};
