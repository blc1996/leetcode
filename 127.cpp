//BFS
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int flag = -1;
        unordered_map<string, int> s;
        for(unsigned i = 0; i < wordList.size(); i++){
            s[wordList[i]] = i;
            if(!endWord.compare(wordList[i])){
                flag = i;
            }
        }
        if(flag == -1) return 0;
        int mark[wordList.size()] = {0};
        mark[flag] = 1;
        queue<int> q;
        q.push(flag);
        q.push(-1);
        int step = 2;
        while(!q.empty()){
            int num = q.size();
            while(num > 0){
                num--;
                int index = q.front();
                q.pop();
                if(index == -1){
                    step++;
                    continue;
                }
                for(int i = 0; i < wordList.size(); i++){
                    if(difone(beginWord, wordList[index]))
                        return step;
                    if(!difone(wordList[index], wordList[i]))
                        continue;
                    if(s.find(wordList[i]) == s.end())
                        continue;
                    if(!mark[i]){
                        mark[i] = 1;
                        q.push(i);
                    }
                }
            }
            if(!q.empty())
                q.push(-1);
        }
        return 0;
    }

    bool difone(const string& a, const string& b){
        int count = 0;
        for(unsigned i = 0; i < a.size(); i++){
            if(a[i] != b[i])
                count++;
            if(count > 1)
                return false;
        }
        return count==1;
    }
};








class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        return bt(beginWord, endWord, string(), wordList, 0)
    }

    int bt(string& beginWord, string& endWord, string prevWord, vector<string>& wordList, int step){
        int minVal = INT_MAX;
        for(unsigned i = 0; i < wordList.size(); i++){
            if(wordList[i] == endWord)
                return step + 1;
            if(difone(beginWord, wordList[i]) && wordList[i] != prevWord)
                minVal = min(minVal, bt(beginWord, endWord, wordList[i], wordList, step + 1));
        }
        return minVal;
    }

    bool difone(string a, string b){
        int count = 0;
        for(unsigned i = 0; i < a.size(); i++){
            if(a[i] != b[i])
                count++;
            if(count > 1)
                return false;
        }
        return count==1;
    }
};


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int flag = -1;
        for(unsigned i = 0; i < wordList.size(); i++){
            if(!endWord.compare(wordList[i])){
                flag = i;
                break;
            }
        }
        if(flag == -1) return 0;
        int min = wordList.size();
        int mark[wordList.size()] = {0};
        mark[flag] = 1;
        bt(flag, beginWord, wordList, 1, min, mark);
        if(min == wordList.size())
            return 0;
        else
            return min;
    }

    void bt(int begin, string& endWord, vector<string>& wordList, int step, int& min, int* mark){
        if(step >= min){
            mark[begin] = 0;
            return;
        }
        for(unsigned i = 0; i < wordList.size(); i++){
            if(!difone(wordList[begin], wordList[i]))
                continue;
            if(!wordList[i].compare(endWord)){
                min = step + 1;
                return;
            }
            if(mark[i] == 1){
                continue;
            }
            mark[i] = 1;
            bt(i, endWord,wordList, step + 1, min, mark);
        }
        mark[begin] = 0;
    }

    bool difone(const string& a, const string& b){
        int count = 0;
        for(unsigned i = 0; i < a.size(); i++){
            if(a[i] != b[i])
                count++;
            if(count > 1)
                return false;
        }
        return count==1;
    }
};

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool flag = false;
        for(unsigned i = 0; i < wordList.size(); i++){
            if(!endWord.compare(wordList[i])){
                flag = true;
                break;
            }
        }
        if(!flag) return 0;
        int min = wordList.size();
        bt(beginWord, endWord, beginWord, wordList, 1, min);
        if(min == wordList.size())
            return 0;
        else
            return min;
    }

    void bt(string& beginWord, string& endWord, string& prevWord, vector<string>& wordList, int step, int& min){
        if(step >= wordList.size() || step >= min)
            return;
        for(unsigned i = 0; i < wordList.size(); i++){
            if(!difone(beginWord, wordList[i]))
                continue;
            if(!wordList[i].compare(endWord)){
                min = step + 1;
                continue;
            }
            if(wordList[i].compare(prevWord))
                bt(wordList[i], endWord, beginWord, wordList, step + 1, min);
        }
    }

    bool difone(const string& a, const string& b){
        int count = 0;
        for(unsigned i = 0; i < a.size(); i++){
            if(a[i] != b[i])
                count++;
            if(count > 1)
                return false;
        }
        return count==1;
    }
};


