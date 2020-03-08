class Solution {
public:
    bool checkValid(vector<int>& map){
        for(int i = 0; i < 256; i++){
            if(map[i] > 0){
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        vector<int> map(256, 0);
        for(auto c : t){
            map[c]++;
        }
        int j = 0, n = s.size();
        string res = s;
        bool found = false, tempValid = false;
        for(int i = 0; i < n; i++){
            while(j <= n){
                if(tempValid || checkValid(map)){
                    found = true;
                    tempValid = true;
                    if(j - i < res.size()){
                        res = s.substr(i, j - i);
                    } 
                    break;
                }
                if(j < n) map[s[j]]--;
                j++;
            }
            map[s[i]]++;
            if(map[s[i]] > 0) tempValid = false;
        }
        return found ? res : "";
    }
};