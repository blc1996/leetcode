class Solution {
public:
    bool checkValidString(string s) {
        int left = 0, starLeft = 0, starMatched = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                left++;
            }else if(s[i] == ')'){
                if(left){
                    left--;
                }else if(starLeft){
                    starLeft--;
                }else if(starMatched){
                    starMatched--;
                    starLeft++;
                }else{
                    return false;
                }
            }else{
                if(left){
                    starMatched++;
                    left--;
                }else{
                    starLeft++;
                }
            }
        }
        return !left;
    }
};