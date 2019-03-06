class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> secret_map;
        for(int i = 0; i < secret.size(); i++){
            secret_map[secret[i]]++;
        }
        vector<int> temp;
        int A = 0, B = 0;
        for(int i = 0; i < guess.size(); i++){
            if(secret_map[guess[i]] > 0){
                if(secret[i] == guess[i]){
                    A++;
                }else{
                    B++;
                }
                secret_map[guess[i]]--;
            }else if(secret[i] == guess[i]){
                A++;
                B--;
            }
        }
        return to_string(A) + 'A' + to_string(B) + 'B';
    }
};
