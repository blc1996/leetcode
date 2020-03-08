class Solution {
public:
    bool isNext(char a, char b){
        if(a == 'z'){
            return b == 'a';
        }else{
            return b == a + 1;
        }
    }

    int findSubstringInWraproundString(string p) {
        vector<bool> next(p.size(), false);
        for(int i = 1; i < p.size(); i++){
            next[i] = isNext(p[i-1], p[i]);
        }
        
        vector<int> maxCount(26, 0);
        
        for(int i = 0; i < p.size(); i++){
            int count = 1;
            while(i + count < p.size() && next[i + count]){
                count++;
            }
            maxCount[p[i] - 'a'] = max(maxCount[p[i] - 'a'], count);
        }
        int sum = 0;
        for(int i = 0; i < 26; i++){
            sum += maxCount[i];
        }
        return sum;
    }
};

//DP

class Solution {
public:
    bool isNext(char a, char b){
        if(a == 'z'){
            return b == 'a';
        }else{
            return b == a + 1;
        }
    }

    int findSubstringInWraproundString(string p) {
        vector<int> letters(26, 0);

        int res = 0, len = 0;
        for(int i = 0; i < p.size(); i++){
            if(i > 0 && !isNext(p[i-1], p[i])){
                len = 0;
            }
            int index = p[i] - 'a';
            if(++len > letters[index]){
                res += len - letters[index];
                letters[index] = len;
            }
        }
        return res;
    }
};