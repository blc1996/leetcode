class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int length = arr.size();
        vector<int> dp(length, 0), rDp(length, 0);
        int maxSum = INT_MIN, curSum = 0;
        for(int i = 0; i < length; i++){
            curSum += arr[i];
            maxSum = max(maxSum, curSum);
            dp[i] = curSum;
            if(curSum < 0) curSum = 0;
        }
        curSum = 0;
        for(int i = length - 1; i >= 0; i--){
            curSum += arr[i];
            maxSum = max(maxSum, curSum);
            rDp[i] = curSum;
            if(curSum < 0) curSum = 0;
        }

        for(int i = 1; i < length - 1; i++){
            maxSum = max(maxSum, dp[i - 1] + rDp[i + 1]);
        }
        return maxSum;
    }
};