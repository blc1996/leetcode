#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include <unordered_map>

using namespace std;



bool isPrime(int num){
    if(num == 1) return false;
    int limit = sqrt(num);
    for(int i = 2; i <= limit; i++){
        if(num % i == 0) return false;
    }
    return true;
}

vector<bool> prime;
unordered_map<int, int> mp;

void countPrimeStringsCore(const string& s, int index, long& sum){
    if(s[index] == '0') return;
    if(index == s.size()){
        sum++;
        sum %= 1000000007;
        return;
    }
    if(mp.count(index)){
        sum += mp[index];
        sum %= 1000000007;
        return;
    }
    int originalSum = sum;
    for(int i = 1; i < 7 && index + i <= s.size(); i++){
        int tempNum = stoi(s.substr(index, i));
        if(isPrime(tempNum)){
            countPrimeStringsCore(s, index + i, sum);
        }
    }
    mp[index] = sum - originalSum;
}

int countPrimeStrings(string s){
    long sum = 0;
    // prime = vector<bool>(1000000, true);
    // prime[1] = false;
    // for(unsigned i = 2; i < 1000000; i++){
    //     if(prime[i] == true){
    //         int temp = i + i;
    //         while(temp < 1000000){
    //             prime[temp] = false;
    //             temp += i;
    //         }
    //     }
    // }
    mp = unordered_map<int, int>();
    countPrimeStringsCore(s, 0, sum);
    return sum;
}

int main(){
    string s("5423156423165423151451");
    cout<<countPrimeStrings(s)<<endl;
    return 0;
}


int countDiceSequences(int N, vector<int>& rollMax) {
    vector<vector<vector<int>>> dp(N, vector<vector<int>>(6, vector<int>(16, 0)));
    for(int i = 0; i < 6; i++) {
        dp[0][i][1] = 1;
    }
    for(int i = 1; i < N; i++) {
        for(int j = 0; j < 6; j++) {
            for(int k = 0; k < 6; k++) {
                if(k == j) { continue; }
                for(int m = 1; m <= rollMax[k]; ++m) {
                    dp[i][j][1] = (dp[i][j][1] + dp[i - 1][k][m]) % 1000000007;
                }
            }
            
            for(int m = 2; m <= rollMax[j]; m++) {
                dp[i][j][m] = dp[i - 1][j][m - 1];
            }
        }
    }
    
    int res = 0;
    for(int i = 0; i < 6; i++) {
        for(int j = 1; j <= rollMax[i]; j++) {
            res = (res + dp[N - 1][i][j]) % 1000000007;
        }
    }
    return res;
}