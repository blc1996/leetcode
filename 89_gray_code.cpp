class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> output(1<<n, 0);
        int temp = 0;
        for(int i = 1; i <= 1<<n; i++){
            output[i - 1] = temp;
            temp = 0;
            int pow = 1;
            for(int j = 0; j < n; j++){
                temp += (((i >> 1) & pow) + (i & pow)) & pow;
                pow = pow << 1;
            }
        }
        return output;
    }
};
