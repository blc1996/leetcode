class Solution {
public:
    string toHex(int num) {
        string output;
        for(int i = 0; i < 8; i++){
            int base = 4 * i, sum = 0;
            for(int j = 0; j < 4; j++){
                sum += pow(2, j) * ((num >> (base + j)) & 1);
            }
            if(sum > 9){
                output.insert(output.begin(), 'a' + sum - 10);
            }else{
                output.insert(output.begin(), '0' + sum);
            }
        }
        int ptr = 0;
        while(output[ptr] == '0'){
            ptr++;
        }
        if(ptr >= output.size()){
            return string("0");
        }
        return output.substr(ptr, output.size() - ptr);
    }
};