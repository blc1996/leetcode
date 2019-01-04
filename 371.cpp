class Solution {
public:
    int getSum(int a, int b) {
        bool carry = false;
        int result = 0;
        for(int i = 0; i < 32; i++){
            bool first = ((a >> i) & 1) == 1, second = ((b >> i) & 1) == 1;
            int count = 0;
            if(first)
                count++;
            if(second)
                count++;
            if(carry)
                count++;
            if(count == 1){
                carry = false;
                result |= (1 << i);
            }else if(count == 2){
                carry = true;
            }else if(count == 3){
                carry = true;
                result |= (1 << i);
            }
        }
        return result;
    }
};
