class Solution {
public:
    bool isValid(string s) {
        int l = s.size();
        if(l == 0){
            return true;
        }
        vector<int> dp(l, 0);
        for(int i = 1; i < l; i++){
            if(dp[i - 1] < i && isMatch(s[i - 1 - dp[i - 1]], s[i])){
                dp[i] = dp[i - 1] + 2;
            }
            int tempIdx = i - dp[i];
            while(tempIdx >= 0 && dp[tempIdx]){
                dp[i] += dp[tempIdx];
                tempIdx -= dp[tempIdx];
            }
        }
        return dp.back() == l;
    }

    bool isMatch(char left, char right){
        if(left == '{' && right == '}') return true;
        if(left == '[' && right == ']') return true;
        if(left == '(' && right == ')') return true;
        return false;
    }
};