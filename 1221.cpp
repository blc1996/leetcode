class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0, res = 0;
        for(char c: s){
            if(c == 'R'){
                count++;
            }else{
                count--;
            }
            if(count == 0){
                res++;
            }
        }
        return res;
    }
};