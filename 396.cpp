class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int sum = A[0], idx = 0;
        for(int i = 1; i < A.size(); i++){
            if(A[(idx + i) % A.size()] * i >= sum){
                // just put it into the array
                sum += A[(idx + i) % A.size()];
            }else{
                sum += A[(idx + i) % A.size()] - A[idx % A.size()];
                idx++;
                i--;
            }
        }
        sum = 0;
        for(int i = 0; i < A.size(); i++){
            sum += i * A[(idx + i) % A.size()];
        }
        return sum;
    }
};

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int total = 0, cur = 0, size = A.size();
        for (int i = 0; i < size; i++) {
            total += A[i];
            cur += A[i] * i;
        }

        int max = cur;
        for (int pivot = size - 1; pivot > 0; pivot--) {
            cur += total - A[pivot] * size;
            max = cur > max ? cur : max;
        }

        return max;
    }
};
