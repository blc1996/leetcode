class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string, int> bankMap;
        for(int i = 0; i < bank.size(); i++){
            bankMap.insert({bank[i], i});
        }
        int res = minMutationCore(start, end, bank, bankMap);
        return res == INT_MAX - 1 ? -1 : res;
    }

    int minMutationCore(string start, string end, vector<string>& bank, unordered_map<string, int>& bankMap){
        if(start == end){
            return 0;
        }
        int tempMinCount = INT_MAX - 1;
        for(int i = 0; i < bank.size(); i++){
            if(diffHelper(start, bank[i])){
                if(bankMap.count(start)){
                    bank[bankMap[start]] = "";
                }
                tempMinCount = min(tempMinCount, 1 + minMutationCore(bank[i], end, bank, bankMap));
                if(bankMap.count(start)){
                    bank[bankMap[start]] = start;
                }
            }

        }
        return tempMinCount;
    }

    bool diffHelper(string a, string b){
        if(a.size() != b.size()){
            return false;
        }
        bool diff = false;
        for(int i = 0; i < a.size(); i++){
            if(a[i] != b[i]){
                if(!diff){
                    diff = true;
                }else{
                    return false;
                }
            }
        }
        return diff;
    }
};