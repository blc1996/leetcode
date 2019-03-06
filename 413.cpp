class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() < 3)
            return 0;
        vector<int> temp;
        int diff = A[1] - A[0], count = 2;
        for(int i = 2; i < A.size(); i++){
            if(diff != A[i] - A[i-1]){
                if(count > 2)
                    temp.push_back(count);
                count = 2;
                diff = A[i] - A[i-1];
            }else{
                count++;
            }
        }
        if(count > 2)
            temp.push_back(count);

        int num = 0;
        for(int i = 0; i < temp.size(); i++){
            num += calculate(temp[i]);
        }

        return num;
    }

    int calculate(int n){
        if(n < 3){
            return 0;
        }else if(n == 3){
            return 1;
        }else{
            return 2*calculate(n-1) - calculate(n-2) + 1;
        }
    }
};
