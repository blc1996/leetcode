class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> v(26, vector<int>());
        for(int i = 0; i < t.size(); i++){
            v[t[i] - 'a'].push_back(i);
        }
        int index = -1;
        for(int i = 0; i < s.size(); i++){
            bool flag = false;
            for(int j : v[s[i] - 'a']){
                if(j > index){
                    index = j;
                    flag = true;
                    break;
                }
            }
            if(!flag){
                return false;
            }
        }
        return true;
    }
};