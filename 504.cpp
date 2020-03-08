class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0){
            return string("0");
        }
        bool flag = num < 0 ? false : true;
        num = abs(num);
        int base = 7, prev = 1;
        string res;
        while(num > 0){
            int temp = num % base;
            res.push_back((temp / prev) + '0');
            num -= temp;
            base *= 7;
            prev *= 7;
        }
        if(!flag){
            res.push_back('-');
        }
        return string(res.rbegin(), res.rend());
    }
};