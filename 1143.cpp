class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.size(), l2 = text2.size();
        vector<int> dp(l1, 0);
        for(char c : text2){
            for(int i = 0, temp = 0; i < l1; i++){
                if(dp[i] > temp){
                    temp = dp[i];
                }else if(text1[i] == c && temp >= dp[i]){
                    dp[i] = temp + 1;
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};