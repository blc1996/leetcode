class Solution {
public:
    bool repeatedSubstringPattern(string str) {
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
        int lastNum = dp.back();
        // cout<<lastNum<<endl;
        return lastNum && lastNum % (length - lastNum) == 0;
    }
};

// KMP