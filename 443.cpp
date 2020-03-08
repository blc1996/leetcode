class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size() == 0){
            return 0;
        }
        chars.push_back(0);
        char prev = chars[0];
        int rep = 1, res = 0;
        for(int i = 1; i < chars.size(); i++){
            if(chars[i] != prev){
                chars[res++] = prev;
                vector<char> temp;
                while(rep > 1){
                    temp.push_back('0' + rep % 10);
                    rep /= 10;
                }
                for(auto it = temp.rbegin(); it != temp.rend(); it++){
                    chars[res++] = *it;
                }
                prev = chars[i];
                rep = 1;
            }else{
                rep++;
            }
        }
        return res;
    }
};