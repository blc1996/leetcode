class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> v(26, 0);
        for(int i = 0; i < s.size(); i++){
            v[s[i] - 'a']++;
            v[t[i] - 'a']--;
        }
        v[t[t.size() - 1] - 'a']--;
        for(int i = 0; i < 26; i++){
            if(v[i] == -1){
                return i + 'a';
            }
        }
        return 'a';
    }
};