// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        return helper(1, n);
    }

    int helper(int lower, int higher){
        if(lower > higher)
            return -1;
        int attempt = lower + (higher - lower)/2;
        int flag = guess(attempt);
        if(flag == 0)
            return attempt;
        else if(flag == 1){
            return helper(attempt + 1, higher);
        }else{
            return helper(lower, attempt - 1);
        }
    }
};
