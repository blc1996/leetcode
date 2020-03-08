class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        if(A.size() == 0) return 0;
        vector<int> a(7, -1);
        vector<int> b(7, -1);
        a[A[0]] = 1; b[A[0]] = 0;
        b[B[0]] = 1; a[B[0]] = max(0, a[B[0]]);
        for(int i = 1; i < A.size(); i++){
            if(A[0] != A[i] && A[0] != B[i]){
                a[A[0]] = -1; b[A[0]] = -1;
            }
            if(B[0] != A[i] && B[0] != B[i]){
                a[B[0]] = -1; b[B[0]] = -1;
            }
            if(a[A[0]] == -1 && a[B[0]] == -1){
                return -1;
            }
            if(a[A[i]] != -1){
                a[A[i]]++;
            }
            if(a[B[i]] != -1){
                b[B[i]]++;
            }
        }
        cout<<A.size()<<endl;
        int res = INT_MAX, size = A.size();
        if(a[A[0]] != -1) res = min(size - a[A[0]], size - b[A[0]]);
        if(a[B[0]] != -1) res = min(res, min(size - a[B[0]], size - b[B[0]]));
        return res == INT_MAX ? -1 : res;
    } 
};