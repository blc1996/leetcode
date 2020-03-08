class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] || (i && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                } else {
                    dp[i][j] = i && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return dp[m][n];
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        int offset = p.find('*');
        int index = offset == -1 ? p.size(): offset - 1;
        for(int i = 0; i < index; i++){
            if(i >= s.size() || (p[i] != '.' && p[i] != s[i])){
                return false;
            }
        }
        if(offset == -1){
            return p.size() == s.size();
        }else{
            if(isMatch(string(s, offset - 1), string(p, offset + 1))) return true;
            if(p[offset - 1] == '.'){
                int sIdx = offset - 1;
                while(sIdx < s.size()){
                    if(isMatch(string(s, sIdx + 1), string(p, offset + 1))) return true;
                    sIdx++;
                }
            }else{
                int sIdx = offset - 1;
                while(s[sIdx] == p[offset - 1]){
                    if(isMatch(string(s, sIdx + 1), string(p, offset + 1))) return true;
                    sIdx++;
                }
            }
            return false;
        }
    }
};