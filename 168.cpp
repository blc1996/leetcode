class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while(n > 0){
            n -= 1;
            res.push_back(n % 26 + 'A');
            n /= 26;
        }
        return string(res.rbegin(), res.rend());
    }
};