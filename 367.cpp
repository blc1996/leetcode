class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1, right = num;
        while(left <= right){
            int idx = left + (right - left) / 2;
            int check = INT_MAX / idx;
            if(check < idx){
                right = idx - 1;
                continue;
            }
            int temp = idx * idx;
            if(temp == num){
                return true;
            }else if(temp > num){
                right = idx - 1;
            }else{
                left = idx + 1;
            }
        }
        return false;
    }
};
