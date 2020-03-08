class Solution {
public:
    bool checkValid(vector<bool>& storeA, vector<bool>& storeB){
        for(int i = 0; i < 26; i++){
            if(storeA[i] && storeB[i]) return false;
        }
        return true;
    }

    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<vector<bool>> store(n, vector<bool>(26, false));
        for(int i = 0; i < n; i++){
            const string& s = words[i];
            for(char c : s){
                store[i][c - 'a'] = true;
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(checkValid(store[i], store[j])) res = max(res, (int)(words[i].size() * words[j].size()));
            }
        }
        return res;
    }
};



class Solution {
public:
    inline int encode(const string& s){
        int res = 0;
        for(char c : s){
            res |= 1 << (c - 'a');
        }
        return res;
    }

    inline bool isValid(int codeA, int codeB){
        return (codeA & codeB) == 0;
    }

    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> codeStore(n, 0);
        for(int i = 0; i < n; i++){
            codeStore[i] = encode(words[i]);
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(isValid(codeStore[i], codeStore[j])) res = max(res, (int)(words[i].size() * words[j].size()));
            }
        }
        return res;
    }
};