class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> mp;
        for(string s: strs){
            string tempS = s;
            sort(s.begin(), s.end());
            if(mp.count(s)){
                res[mp[s]].push_back(tempS);
            }else{
                mp.insert({s, res.size()});
                res.push_back(vector<string>());
                res.back.push_back(tempS);
            }
        }
        return res;
    }
};