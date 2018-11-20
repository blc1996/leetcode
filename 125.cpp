class Solution {
public:
    bool isPalindrome(string s) {
        unsigned i = 0, bi = s.size() - 1;
        while(i < s.size()){
            if(!isalpha(s[i]) && !isdigit(s[i])){
                i++;
                continue;
            }
            if(!isalpha(s[bi]) && !isdigit(s[bi])){
                bi--;
                continue;
            }
            if((s[i] | 0x20) != (s[bi] | 0x20)) //was toupper, bottleneck
                return false;
            i++; bi--;
        }
        return true;
    }
};
