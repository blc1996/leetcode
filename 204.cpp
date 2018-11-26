class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<bool> prime(n, true);
        for(unsigned i = 2; i < n; i++){
            if(prime[i] == true){
                count++;
                int temp = i;
                while(temp < n){
                    prime[temp] = false;
                    temp += i;
                }
            }
        }
        return count;
    }
};
