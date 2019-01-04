class Solution {
public:
    bool isPowerOfTwo(int n) {
        for(long i = 1; i <= n;){
            if(i == n)
                return true;
            i = i << 1;
        }
        return false;
    }
};
