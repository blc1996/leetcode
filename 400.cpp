class Solution {
public:
    int findNthDigit(int n) {
        long count = 0, idx = 0, p = 1;
        while(count < n){
            count += 9 * (idx + 1) * p;
            p *= 10;
            idx++;
        }
        p /= 10;
        count -= 9 * idx * p;
        n -= count;
        int remain = n % idx;
        n += idx - 1;
        n /= idx;
        string temp = to_string(p + n - 1);
        if(remain == 0)
            return temp[idx - 1] - '0';
        return temp[remain - 1] - '0';
    }
};

