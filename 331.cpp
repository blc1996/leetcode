class Solution {
public:
    bool isValidSerialization(string preorder) {
        int remain = 1;
        preorder.push_back(',');
        vector<string> store;
        int prev = 0;
        for(int i = 0; i < preorder.size(); i++){
            if(preorder[i] == ','){
                store.push_back(preorder.substr(prev, i - prev));
                prev = i + 1;
            }
        }
        for(string s : store){
            if(remain <= 0){
                return false;
            }
            if(s == "#"){
                remain--;
            }else{
                remain++;
            }
        }
        return remain == 0;
    }
};