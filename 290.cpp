class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> splited;
        str.push_back(' ');
        int left = 0, right = 0;
        while(right < str.size() - 1){
            while(str[right + 1] != ' ')
                right++;
            splited.push_back(str.substr(left, right + 1 - left));
            right += 2;
            left = right;
        }
        if(splited.size() != pattern.size())
            return false;
        unordered_map<char, string> map;
        unordered_set<string> set;
        for(int i = 0; i < pattern.size(); i++){
            if((map.count(pattern[i])) == 0 && (set.count(splited[i]) == 0)){
                map.insert({pattern[i], string(splited[i])});
                set.insert(splited[i]);
            }else{
                if(map[pattern[i]] != splited[i]){
                    return false;
                }
            }
        }
        return true;
    }
};
