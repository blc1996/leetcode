class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size()){
            return vector<int>();
        }
        int exist[26] = {0};
        int cmp[26] = {0};
        int length = p.size();
        for(int i = 0; i < length; i++){
            exist[p[i] - 'a']++;
            exist[s[i] - 'a']--;
        }
        vector<int> res;
        for(int i = length; i < s.size(); i++){
            if(memcmp(exist, cmp, 26 * sizeof(int)) == 0){
                res.push_back(i - length);
            }
            exist[s[i] - 'a']--;
            exist[s[i - length] - 'a']++;
        }
        if(memcmp(exist, cmp, 26 * sizeof(int)) == 0){
            res.push_back(s.size() - length);
        }
        return res;
    }
};