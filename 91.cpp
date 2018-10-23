class Solution {
public:
    int numDecodings(string s) {
        int res = 0;
        backTrack(s, s.size() - 1, 1, res);
        backTrack(s, s.size() - 1, 2, res);
        return res;
    }

    void backTrack(string &s, int pos, int step, int &res){
        if(step == 1){
            if(s[pos] == '0')
                return;
            if(pos == 0){
                res++;
                return;
            }
            backTrack(s, pos - 1, 1, res);
            backTrack(s, pos - 1, 2, res);
        }else if(step == 2){
            if(pos < 1 || s[pos - 1] == '0'){
                return;
            }
            if(s[pos - 1] < '2' || ( s[pos - 1] == '2' && s[pos] < '7')){
                if(pos == 1){
                    res++;
                    return;
                }
                backTrack(s, pos - 2, 1, res);
                backTrack(s, pos - 2, 2, res);
            }
        }
    }
};

/*

 */

class Solution {
public:
    int numDecodings(string s) {
        if(s.size() < 1)
            return 0;

        if(s[0] == '0')
            return 0;

        int result[s.size() + 1];
        result[0] = 1;
        result[1] = 1;

        for(int i = 1; i < s.size(); i++){
            if(s[i] == '0') {
                if(s[i-1] == '1' || s[i-1] == '2') {
                    result[i+1] = result[i-1];
                } else {
                    return 0;
                }
            }else if( s[i - 1] == '1' || ( s[i - 1] == '2' && s[i] < '7')){
                result[i + 1] = result[i] + result[i - 1];
            }else{
                result[i+1] = result[i];
            }
        }
        return result[s.size()];
    }
};
