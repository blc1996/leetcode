class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string rResult;
        int rem = K;
        for(int i = S.size() - 1; i >= 0; i--){
            if(S[i] != '-'){
                if(rem == 0){
                    rem = K;
                    rResult.push_back('-');
                }
                rResult.push_back(toupper(S[i]));
                rem--;
            }
        }
        return string(rResult.rbegin(), rResult.rend());
    }
};