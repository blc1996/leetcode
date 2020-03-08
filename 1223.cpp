class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        unordered_map<int, int> mp;
        for(int i : rollMax){
            mp[i]++;
        }
        int res = 1, totalResdual = 0;
        for(int i = 1; i <= n; i++){
            int deduct = totalResdual * (totalResdual + mp[i - 1]) + mp[i - 1];
            totalResdual += mp[i - 1];
            res = res * 6 - deduct;
        }
        return res;
    }
};