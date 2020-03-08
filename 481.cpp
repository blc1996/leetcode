class Solution {
public:
    int magicalString(int n) {
        string magicNum = "122";
        int index = 2;
        bool one = true;
        while(magicNum.size() < n){
            char nextChar = one ? '1' : '2';
            one = !one;
            if(magicNum[index++] == '2'){
                magicNum.push_back(nextChar);
                magicNum.push_back(nextChar);
            }else{
                magicNum.push_back(nextChar);
            }
        }

        int res = 0;
        for(int i = 0; i < n; i++){
            if(magicNum[i] == '1') res++;
        }

        return res;
    }
};