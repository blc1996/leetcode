class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        vector<pair<int, int>> dp(A.size() + 1, pair<int, int>(0, 0));
        for(int i = 0; i < A.size(); i++){
            int curIdx = i;
            int sum = A[curIdx--];
            while(curIdx >= 0 && (abs(sum) % K != 0)){
                sum += A[curIdx--];
            }
            if(abs(sum) % K != 0){
                dp[i + 1] = pair<int, int>(0, dp[i].second);
            }else{
                dp[i + 1] = pair<int, int>(dp[curIdx + 1].first + 1, dp[i].second + dp[curIdx + 1].first + 1);
            }
        }
        return dp.back().second;
    }
};