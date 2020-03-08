class Solution {
public:
    string shortestPalindrome(string s) {
        string str = s + "*" + string(s.rbegin(), s.rend());
        int length = str.size();
        vector<int> dp(length, 0);
        for(int i = 1, j = 0; i < length;){
            if(str[i] == str[j]){
                dp[i++] = ++j;
            }else{
                if(j == 0){
                    dp[i++] = 0;
                }else{
                    j = dp[j - 1];
                }
            }
        }
        return string(s.rbegin(), s.rbegin() + s.size() - dp.back()) + s;
    }
};