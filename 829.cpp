class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int num = 2 * N, res = 0;
        int left = 1, right = num;
        while(left < right){
            if((left + right) % 2 != 0){
                res++;
            }
            while(num % (++left));
            right = num / left;
        }
        return res;
    }
};