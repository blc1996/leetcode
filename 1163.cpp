string lastSubstring(string s, int i = 0, int sz = 0) {
  for (auto j = 1; j < s.size(); ++j) {
    for (sz = 0; j + sz < s.size(); ++sz) {
      if (s[i + sz] == s[j + sz]) continue;
      i = s[j + sz] > s[i + sz] ? j : i;
      break;
    }
    if (j + sz == s.size()) break;
  }
  return s.substr(i);
}

class Solution {
public:
    string lastSubstring(string s) {
        char largestLetter = 'a' - 1;
        vector<int> letterIndex;
        for(int i = 0; i < s.size(); i++){
            if(s[i] > largestLetter){
                largestLetter = s[i];
                letterIndex.clear();
            }
            if(s[i] == largestLetter){
                letterIndex.push_back(i);
            }
        }
        vector<string> stringBank;
        for(int i : letterIndex){
            stringBank.push_back(string(s.begin() + i, s.end()));
        }
        string res = "";
        for(string s : stringBank){
            if(s > res) res = s;
        }
        return res;
    }
};