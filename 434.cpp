class Solution {
public:
    int countSegments(string s) {
        if(s.size() == 0){
            return 0;
        }
        int count = 0, length = s.size();
        bool space = true;
        for(int i = 0; i < length; i++){
            if(s[i] == ' '){
                space = true;
            }else if(space){
                count++;
                space = false;
            }
        }
        return count;
    }
};