class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m == 0)
            return 0;
        int i = 0;
        while((int)(m / pow(2,i)) != 0){
            i++;
        }
        if((int)(n / pow(2, i)) == 0)
            return pow(2, i-1) + rangeBitwiseAnd(m - pow(2, i-1), n - pow(2, i-1));
        else
            return 0;
    }
};



class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m == 0)
            return 0;
        int i = 0;
        int temp = 1;
        while((int)(m / temp) != 0){
            i++;
            temp <<= 1;
        }
        if((int)(n / temp) == 0){
            temp >>= 1;
            return temp + rangeBitwiseAnd(m - temp, n - temp);
        }
        else
            return 0;
    }
};
