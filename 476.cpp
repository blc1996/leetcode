class Solution {
public:
    int findComplement(int num) {
        bool flag = false;
        int res = 0;
        for(int i = 31; i >= 0; i--){
            if( num & 1 << i ) {
                flag = true;
            }else if(flag){
                res = res | (1 << i);
            }
        }
        return res;
    }
};