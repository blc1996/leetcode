
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        vector<int> first, second;
        combineTwo(A, B, first);
        combineTwo(C, D, second);

        unordered_map<int, int> store;
        for(int i : first){
            if(!store.count(i)){
                store.insert({i, 1});
            }else{
                store[i]++;
            }
        }
        int res = 0;
        for(int i : second){
            if(store.count(-i)){
                res += store[-i];
            }
        }
        return res;
    }

    void combineTwo(vector<int>&A, vector<int>& B, vector<int>& target){
        int length = A.size();
        for(int i = 0; i < length; i++){
            for(int j = 0; j < length; j++){
                target.push_back(A[i] + B[j]);
            }
        }
    }
};