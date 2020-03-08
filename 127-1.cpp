class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> mp;
        wordList.push_back(beginWord);
        int l = wordList.size();
        for(int i = 0; i < l; i++){
            for(int j = 0; j < l; j++){
                if(i != j && canChange(wordList[i], wordList[j])){
                    mp[wordList[i]].push_back(wordList[j]);
                    mp[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        if(!mp.count(endWord)){
            return 0;
        }
        unordered_map<string, string> parents;
        parents.insert({beginWord, ""});
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()){
            string cur = q.front();
            if(cur == endWord){
                return constructAnswer(parents, beginWord, endWord);
            }
            q.pop();
            for(auto it = mp[cur].begin(); it != mp[cur].end(); it++){
                if(!parents.count(*it)){
                    parents.insert({*it, cur});
                    q.push(*it);
                }
            }
        }
        return 0;
    }

    int constructAnswer(unordered_map<string, string>& parents, string beginWord, string endWord){
        string curStr = endWord;
        int res = 1;
        while(curStr != beginWord){
            res++;
            curStr = parents[curStr];
        }
        return res;
    }

    bool canChange(const string& a, const string& b){
        int count = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] != b[i]){
                count++;
            }
            if(count > 1) return false;
        }
        return count == 1;
    }
};