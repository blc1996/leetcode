class Solution {
public:
    int countSubstrings(string s) {
        int left = 0, right = 0, length = s.size(), res = 0;
        while(left < length && right < length){
            int limit = length - right;
            if(s[left] == s[right]){
                res++;
                int index = 1;
                while(index <= left && index < limit && s[left - index] == s[right + index]){
                    res++;index++;
                }
                // cout<<left<<" "<<right<<" "<<res<<endl;
            }
            left == right ? right++ : left++;
        }
        return res;
    }
};