class Solution {
public:
    void parseAndAdd(const string& s, unordered_map<string, int>& mp){
        int idx = 0;
        while(s[idx] != ' ') idx++;
        int count = stoi(s.substr(0, idx));
        mp[s.substr(idx + 1)] += count;
        for(int i = idx + 1; i < s.size(); i++){
            if(s[i] == '.'){
                mp[s.substr(i + 1)] += count;
            }
        }
    }

    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> mp;
        for(auto s : cpdomains){
            parseAndAdd(s, mp);
        }
        vector<string> res;
        for(auto it = mp.begin(); it != mp.end(); it++){
            res.push_back(to_string(it->second) + " " + it->first);
        }
        return res;
    }
};