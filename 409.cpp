class Solution {
public:
    int longestPalindrome(string s) {
        int a[256] = {0};
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            a[s[i]]++;
            if(a[s[i]] == 2){
                count += 2;
                a[s[i]] = 0;
            }
        }
        if(s.size() > count){
            return count + 1;
        }else{
            return count;
        }
    }
};

