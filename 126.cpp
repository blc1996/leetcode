class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> mp;
        wordList.push_back(beginWord);
        int l = wordList.size();
        for(int i = 0; i < l; i++){
            for(int j = i + 1; j < l; j++){
                if(canChange(wordList[i], wordList[j])){
                    mp[wordList[i]].push_back(wordList[j]);
                    mp[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        if(!mp.count(endWord)){
            return vector<vector<string>>();
        }
        unordered_multimap<string, string> children;
        unordered_map<string, int> levelMp;
        queue<pair<string, int>> q;
        q.push(pair<string, int>(beginWord, 0));
        while(!q.empty()){
            string cur = q.front().first;
            int level = q.front().second;
            if(cur == endWord){
                vector<string> temp({beginWord});
                return constructAnswer(children, endWord, temp);
            }
            q.pop();
            for(auto it = mp[cur].begin(); it != mp[cur].end(); it++){
                if((!levelMp.count(*it) || level + 1 <= levelMp[*it]) && !children.count(*it)){
                    levelMp[*it] = level + 1;
                    children.insert({cur, *it});
                    q.push(pair<string, int>(*it, level + 1));
                }
            }
        }
        return vector<vector<string>>();
    }

    vector<vector<string>> constructAnswer(unordered_multimap<string, string>& children, string endWord, vector<string>& path){
        string curStr = path.back();
        if(curStr == endWord) return vector<vector<string>>({path});
        
        set<vector<string>> res;
        auto range = children.equal_range(curStr);
        for_each (
            range.first,
            range.second,
            [&](auto x){
                path.push_back(x.second);
                auto temp = constructAnswer(children, endWord, path);
                res.insert(temp.begin(), temp.end());
                path.pop_back();
            }
        );
        return vector<vector<string>>(res.begin(), res.end());
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

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> mp;
        if(find(wordList.begin(), wordList.end(), beginWord) == wordList.end())
            wordList.push_back(beginWord);
        int l = wordList.size();
        for(int i = 0; i < l; i++){
            for(int j = i + 1; j < l; j++){
                if(canChange(wordList[i], wordList[j])){
                    mp[wordList[i]].push_back(wordList[j]);
                    mp[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        if(!mp.count(endWord)){
            return vector<vector<string>>();
        }
        vector<vector<string>> ans;
        queue<vector<string>> q;
        int level = 1;
        int minLevel = INT_MAX;
        q.push(vector<string>({beginWord}));

        unordered_set<string, int> visited;

        while(!q.empty()){
            vector<string> curPath = q.front();
            string curStr = curPath.back();
            q.pop();
            if(curPath.size() > level){
                if (curPath.size() > minLevel)
                    break;
                else
                    level = curPath.size();
            }
            
            for(auto it = mp[curStr].begin(); it != mp[curStr].end(); it++){
                if(!visited.count(*it) || level <= visited[*it]){
                    vector<string> newPath = curPath;
                    newPath.push_back(*it);
                    visited.insert({*it, level});
                    if (*it == endWord) {
                        minLevel = level;
                        ans.push_back(newPath);
                    }else
                        q.push(newPath);
                }
            }
        }
        return ans;
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



vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        //very interesting problem
        //It can be solved with standard BFS. The tricky idea is doing BFS of paths instead of words!
        //Then the queue becomes a queue of paths.
        vector<vector<string>> ans;
        queue<vector<string>> paths;
        wordList.insert(endWord);
        paths.push({beginWord});
        int level = 1;
        int minLevel = INT_MAX;
        
        //"visited" records all the visited nodes on this level
        //these words will never be visited again after this level 
        //and should be removed from wordList. This is guaranteed
        // by the shortest path.
        unordered_set<string> visited; 
        
        while (!paths.empty()) {
            vector<string> path = paths.front();
            paths.pop();
            if (path.size() > level) {
                //reach a new level
                for (string w : visited) wordList.erase(w);
                visited.clear();
                if (path.size() > minLevel)
                    break;
                else
                    level = path.size();
            }
            string last = path.back();
            //find next words in wordList by changing
            //each element from 'a' to 'z'
            for (int i = 0; i < last.size(); ++i) {
                string news = last;
                for (char c = 'a'; c <= 'z'; ++c) {
                    news[i] = c;
                    if (wordList.find(news) != wordList.end()) {
                    //next word is in wordList
                    //append this word to path
                    //path will be reused in the loop
                    //so copy a new path
                        vector<string> newpath = path;
                        newpath.push_back(news);
                        visited.insert(news);
                        if (news == endWord) {
                            minLevel = level;
                            ans.push_back(newpath);
                        }
                        else
                            paths.push(newpath);
                    }
                }
            }
        }
        return ans;
    }