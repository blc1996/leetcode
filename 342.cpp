class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num == 0)
            return false;
        bool flag = false;
        for(int i = 0; i < 32; i++){
            if(i % 2 == 0 && ((num >> i) & 1)){
                if(flag)
                    return false;
                else
                    flag = true;
            }else if((num >> i) & 1){
                return false;
            }
        }
        return true;
    }
};

