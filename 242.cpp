class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        int a[26] = {0};
        for(unsigned i = 0; i < s.size(); i++){
            a[s[i] - 'a']++;
        }
        for(unsigned i = 0; i < s.size(); i++){
            if(a[t[i] - 'a']-- == 0)
                return false;
        }
        return true;
    }
};

