class Solution {
public:
    bool isPowerOfThree(int n) {
        int index = 0;
        bool res = false;
        for(int i = 0; i < 32; i++){
            if(n & (1 << i)){
                if(!index){
                    index = i;
                }else if(i == ){
                    res = true;
                }else{
                    return false;
                }
            }
        }
        return res;
    }
};