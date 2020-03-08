class Solution {
public:
    string longestPalindrome(string s) {
        int left = 0, right = 0, length = s.size();
        string res = "";
        while(left < length && right < length){
            int limit = length - right;
            if(s[left] == s[right]){
                int index = 1;
                while(index <= left && index < limit && s[left - index] == s[right + index]){
                    index++;
                }
                int tempLength = 1 + right - left + 2 * (index - 1);
                if(tempLength > res.size()) res = s.substr(left - index + 1, tempLength);
            }
            left == right ? right++ : left++;
        }
        return res;
    }
};