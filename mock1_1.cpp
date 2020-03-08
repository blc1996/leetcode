class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.size() != B.size()){
            return false;
        }
        int l = A.size();
        vector<int> kmp(l, 0);
        for(int i = 1, j = 0; i < l;){
            if(A[i] == A[j]){
                kmp[i++] = ++j;
            }else{
                if(j == 0) kmp[i++] = 0;
                else j = kmp[j - 1];
            }
        }
        int indexA = 0, indexB = 0, count = 0;
        while(indexB < l){
            // cout<<indexA<<" "<<indexB<<endl;
            if(A[indexA] == B[indexB]){
                if(indexA == l - 1) break;
                indexA++; indexB++;
                count++;
            }else{
                if(count == 0){
                    indexB++;
                }else{
                    indexA = kmp[indexA - 1];
                    count = kmp[indexB];
                    // index
                }
            }
        }
        // cout<<indexA<<endl;
        return A.substr(indexA, l - indexA) == B.substr(0, l - indexA);
    }
};