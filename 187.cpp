class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> mp;
        vector<string> res;
        for(int i = 0; i < (int)s.size() - 9; i++){
            string tmp = string(s.begin() + i, s.begin() + i + 10);
            if(mp.count(tmp)){
                mp[tmp]++;
                if(mp[tmp] == 2){
                    res.push_back(tmp);
                }
            }else{
                mp.insert({tmp, 1});
            }
        }
        return res;
    }
};