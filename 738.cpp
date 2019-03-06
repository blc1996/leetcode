class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        vector<int> store;
        int temp = N;
        while(temp > 0){
            store.push_back(temp % 10);
            temp /= 10;
        }
        bool flag = false;
        int count = store.size() - 1;
        while(count > 0){
            if(store[count] > store[count - 1]){
                flag = true;
                break;
            }
            count--;
        }
        if(flag){
            //reconstruct the number
            int result = 0;
            for(int i = store.size() - 1; i > count; i--){
                result = result * 10 + store[i];
            }
            result = result * 10 + store[count] - 1;
            for(int i = 0; i < count; i++){
                result = result * 10 + 9;
            }
            return monotoneIncreasingDigits(result);
        }else{
            return N;
        }
    }
};