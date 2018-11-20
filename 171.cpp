class Solution {
public:
    int titleToNumber(string s) {
        int col = 0;
        for(unsigned i = 0; i < s.size(); i++){
            col = col*26 + s[i] - 'A' + 1;
        }
        return col;
    }
};
