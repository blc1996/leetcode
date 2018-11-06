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
