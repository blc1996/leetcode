class Solution {
public:
    int arrangeCoins(int n) {
        long temp = n;
        temp *= 2;
        long row = sqrtl(temp);
        if(row * (row + 1) > temp){
            return row - 1;
        }else{
            return row;
        }
    }
};