class Solution {
public:

    void search(string s, int index, int count, string result, vector<string>& output){
        if(index < (3 - count))
            return;
        if(count == 3){
            if(index > 2){
                return;
            }else{
                string temp = s.substr(0, index + 1);
                const char *str = temp.c_str();
                if(atoi(str) < 256){
                    if(temp.size() > 1 && str[0] == '0'){
                        return;
                    }
                    result = str + result;
                    output.push_back(result);
                }
                return;
            }
        }

        for(int i = 0; i < 3; i++){
            if(index - i >= 0){
                string temp = s.substr(index - i, i + 1);
                const char *str = temp.c_str();
                if(atoi(str) < 256){
                    if(temp.size() > 1 && str[0] == '0'){
                        continue;
                    }
                    search(s, index - i - 1, count + 1, "." + temp + result, output);
                }
            }
        }
    }


    vector<string> restoreIpAddresses(string s) {
        vector<string> output;
        search(s, s.size() - 1, 0, string(), output);
        return output;
    }
};


class Solution {
public:
    void backtrack(const string& str, int index, int level, string curStr, vector<string>& res){
        if(level == 0){
            if(index == str.size()){
                curStr.pop_back();
                res.push_back(curStr);
            }
            return;
        }
        if(str[index] == '0'){
            curStr.append("0.");
            backtrack(str, index + 1, level - 1, curStr, res);
        }else{
            for(int i = 1; i <= 3 && index + i <= str.size(); i++){
                string tempStr(str.begin() + index, str.begin() + index + i);
                if(stoi(tempStr) < 256){
                    auto tempCurStr = curStr;
                    tempCurStr.append(tempStr);
                    tempCurStr.push_back('.');
                    backtrack(str, index + i, level - 1, tempCurStr, res);
                }
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        backtrack(s, 0, 4, "", res);
        return res;
    }
};
