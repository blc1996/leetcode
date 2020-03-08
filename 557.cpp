class Solution {
public:
    string reverseWords(string s) {
        int idx = 0, prev = 0;
        string res;
        while(idx < s.size()){
            while(s[idx] == ' '){
                idx++;
            }
            prev = idx;
            while(idx < s.size() && s[idx] != ' '){
                idx++;
            }
            string tempStr = string(s.begin() + prev, s.begin() + idx);
            res.append(string(tempStr.rbegin(), tempStr.rend()));
            res.push_back(' ');
        }
        while(res.back() == ' ') res.pop_back();
        return res;
    }
};