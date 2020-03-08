class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(words.size() == 0) return vector<int>();
        int wordLength = words[0].size(), n = s.size();
        unordered_map<string, int> wordMap;
        for(const string& str : words){
            wordMap[str]++;
        }
        int totalCount = words.size();
        vector<int> res;
        for(int i = 0; i < n; i++){
            unordered_map<string, int> tempMap;
            int count = 0;
            while(count < totalCount){
                string tempStr = s.substr(i + count * wordLength, wordLength);
                if(!wordMap.count(tempStr) || ++tempMap[tempStr] > wordMap[tempStr]){
                    break;
                }
                count++;
            }
            if(count == totalCount){
                res.push_back(i);
            }
        }
        return res;
    }
};