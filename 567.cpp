class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp;
        for(char c : s1){
            mp[c]++;
        }
        for(int i = 0; i < s2.size(); i++){
            unordered_map<char, int> tempMp = mp;
            int offset = 0;
            while(i + offset < s2.size() && tempMp.count(s2[i + offset])){
                if(offset == s1.size()) return true;
                while(offset > 0 && tempMp[s2[i + offset]] == 0){
                    tempMp[s2[i++]]++;
                    offset--;
                }
                if(tempMp[s2[i + offset]] > 0){
                    tempMp[s2[i + offset]]--;
                    offset++;
                }
            }
            if(offset == s1.size()){
                return true;
            }else{
                i += offset;
            }
        }
        return false;
    }
}; 

// sliding window!!!