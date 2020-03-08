class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        unordered_map<int, long> mp;
        for(int i : A){
            mp[i]++;
        }
        long res = 0;
        for(int i = 0; i < A.size(); i++){
            for(int j = i + 1; j < A.size(); j++){
                mp[A[i]]--; mp[A[j]]--;
                res = (res + mp[target - A[i] - A[j]]) % 1000000007;
                mp[A[i]]++; mp[A[j]]++;
            }
        }
        return res;
    }
};