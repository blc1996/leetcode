class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())
            return false;
        unordered_map<char, char> m;
        unordered_set<char> set;
        for(unsigned i = 0; i < s.size(); i++){
            if(m.count(s[i])){
                if(m[s[i]] != t[i])
                    return false;
            }else{
                if(set.count(t[i]))
                    return false;
                m[s[i]] = t[i];
                set.insert(t[i]);
            }
        }
        return true;
    }
};
