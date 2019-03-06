class Solution {
public:
    string addStrings(string num1, string num2) {
        int iter = max(num1.size(), num2.size());
        string output(iter + 1, '0');
        for(int i = 0; i < iter; i++){
            int sum = 0;
            if(i < num1.size()){
                sum += num1[num1.size() - 1 - i] - '0';
            }
            if(i < num2.size()){
                sum += num2[num2.size() - 1 - i] - '0';
            }
            if(output[i] != '0'){
                sum++;
            }
            if(sum >= 10){
                output[i + 1] = '1';
            }
            output[i] = (sum % 10) + '0';
        }
        if(output[output.size() - 1] == '0'){
            return string(output.rbegin() + 1, output.rend());
        }else{
            return string(output.rbegin(), output.rend());
        }
    }
};
