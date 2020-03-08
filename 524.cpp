class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        auto cmp = [](const string& a, const string& b){ 
            if(a.size() == b.size()) 
                return a < b; 
            return a.size() > b.size();
        };
        sort(d.begin(), d.end(), cmp);
        for(string target : d){
            if(canMatch(s, target)) return target;
        }
        return string("");
    }

    bool canMatch(const string& s, const string& target){
        int ptr = -1;
        for(int i = 0; i < target.size(); i++){
            ptr++;
            while(ptr < s.size() && target[i] != s[ptr]) ptr++;
            if(ptr >= s.size()) return false;
        }
        return ptr < s.size();
    }
};