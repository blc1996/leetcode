class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> results;
        vector<int> temp;
        helper(k, n, 0, results, temp);
        return results;
    }

    void helper(int k, int n, int m, vector<vector<int>>& results, vector<int>& temp){
        static int low_limit[9] = {1,3,6,10,15,21,28,36,45};
        static int high_limit[9] = {9,17,24,30,35,39,42,44,45};
        if(k == 0){
            if(n == 0){
                results.push_back(vector<int>(temp));
            }
            temp.pop_back();
            return;
        }
        if(n > high_limit[k - 1] || n < low_limit[k - 1]){
            temp.pop_back();
            return;
        }
        for(int i = m + 1; i < 10; i++){
            temp.push_back(i);
            helper(k - 1, n - i, i, results, temp);
        }
        temp.pop_back();
    }
};
