class Solution {
public:
    bool detectCapitalUse(string word) {
        bool capitalFlag = false;
        for(int i = 0; i < word.size(); i++){
            if(i == 0){
                capitalFlag = word[0] < 'a';
            }else if(i == 1){
                if(!capitalFlag && word[1] < 'a'){
                    return false;
                }else{
                    capitalFlag &= (word[1] < 'a');
                }
            }
            if(capitalFlag != (word[i] < 'a')){
                return false;
            }
        }
        return true;
    }
};