class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> set[3];
        set[0] ={'q','w','e','r','t','y','u','i','o','p'};
        set[1] ={'a','s','d','f','g','h','j','k','l'};
        set[2] ={'z','x','c','v','b','n','m'};
        vector<string> output;
        for(string i : words){
            for(int j = 0; j < 3; j++){
                bool flag = true;
                for(int k = 0; k < i.size(); k++){
                    if(set[j].count(tolower(i[k])) == 0){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    output.push_back(i);
                    break;
                }
            }
        }
        return output;
    }
};
