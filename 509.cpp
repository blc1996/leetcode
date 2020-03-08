class Solution {
public:
    int fib(int N) {
        if(N < 2){
            return N;
        }
        int a = 0, b = 1;
        for(int i = 2; i <= N; i++){
            b += a;
            a = b - a;
        }
        return b;
    }
};