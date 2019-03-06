class Solution {
public:
    unordered_set<string> set;
    
    string removeKdigits(string num, int k) {
        return to_string(backtrack(num, k, 0));
    }

    int backtrack(string s, int remain, int start){
        if(remain == 0){
            return getNum(s);
        }
        int minVal = INT_MAX;
        for(int i = start; i < s.size() - remain; i++){
            string temp = string(s);
            temp.erase(temp.begin() + i);
            if(set.count(temp) == 0)
                minVal = min(minVal, backtrack(temp, remain - 1, i));
            else
                set.insert(temp);
        }
        return minVal;
    }
    int getNum(string s){
        int num = 0;
        for(int i = 0; i < s.size(); i++){
            num = num * 10 + s[i] - '0';
        }
        return num;
    }
};