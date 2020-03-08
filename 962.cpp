class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        if(A.size() == 0) return 0;
        vector<int> store;
        int n = A.size(), res = 0;
        for(int i = 0; i < n; i++){
            if(store.size() == 0 || A[i] < A[store.back()]){
                store.push_back(i);
            }else{
                int left = 0, right = store.size() - 1;
                while(left != right){
                    int mid = left + (right - left) / 2;
                    if(A[store[mid]] > A[i]){
                        left = mid + 1;
                    }else{
                        right = mid;
                    }
                }
                // for(auto c : store) cout<<c<<" ";
                // cout<<endl<<left<<endl;
                res = max(res, i - store[left]);
            }
        }
        return res;
    }
};