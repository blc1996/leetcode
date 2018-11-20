class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> results;
        vector<string> temp;
        backTrack(s, temp, results);
        return results;
    }

    void backTrack(string s, vector<string>& temp, vector<vector<string>>& results){
        if(s.size() <= 0){
            results.push_back(temp);
            return;
        }

        for(unsigned i = 1; i <= s.size(); i++){
            if(isPalidrome(s.substr(0, i))){
                temp.push_back(s.substr(0, i));
                backTrack(s.substr(i, s.size() - i), temp, results);
                temp.pop_back();
            }
        }
    }

    bool isPalidrome(const string& s){
        for(unsigned i = 0; i < s.size() / 2; i++){
            if(s[i] != s[s.size() - 1 - i])
                return false;
        }
        return true;
    }
};
