class WordDistance {
public:
    unordered_map<string, vector<int>> mp;
    WordDistance(vector<string>& words) {
        for(int i = 0; i < words.size(); i++){
            mp[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        vector<int>& temp1 = mp[word1];
        vector<int>& temp2 = mp[word2];
        int idx1 = 0, idx2 = 0, res = INT_MAX;
        while(idx1 < temp1.size() && idx2 < temp2.size()){
            res = min(res, abs(temp1[idx1] - temp2[idx2]));
            if(temp1[idx1] < temp2[idx2]){
                idx1++;
            }else{
                idx2++;
            }
        }
        return res;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */