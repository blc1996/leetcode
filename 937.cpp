class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        sort(logs.begin(), logs.end(), [](auto a, auto b){
            string prefix1 = a.substr(0, 3), prefix2 = b.substr(0, 3);
            if(prefix1 != prefix2){
                return prefix1 > prefix2;
            }else{
                string trailer1 = a.substr(4), trialer2 = b.substr(4);
                return trailer1 < trailer2;
            }
        });
        return logs;
    }
};