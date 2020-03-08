class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num <= 0){
            return false;
        }
        int divNum = 1, upper = sqrt(num), sum = -num;
        while(divNum <= upper){
            if(num % divNum == 0){
                if(divNum == num / divNum){
                    sum += divNum;
                }else{
                    sum += divNum + num / divNum;
                }
            }
            divNum++;
        }
        return sum == num;
    }
};