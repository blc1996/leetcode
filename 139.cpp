/* backtrack with path memorization*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        unordered_set<int> path;
        map<int, int> map;
        vector<int> m;
        for(unsigned i = 0; i < wordDict.size(); i++){
            set.insert(wordDict[i]);
            map[wordDict[i].size()] = 1;
        }
        for(auto it = map.rbegin(); it != map.rend(); it++){
            m.push_back(it->first);
        }
        return BT(s, m, set, 0 ,path);
    }

    bool BT(string str, vector<int>& m, unordered_set<string>& s, int depth, unordered_set<int>& path){
        if(path.count(depth))
            return false;
        path.insert(depth);
        for(unsigned i = 0; i < m.size(); i++){
            if(m[i] > str.size())
                continue;
            if(s.count(str))
                return true;
            if(s.count(str.substr(0, m[i]))){
                if(BT(str.substr(m[i], str.size() - m[i]), m, s, depth + m[i], path))
                    return true;
            }
        }
        return false;
    }
};

/* DP */
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        for(unsigned i = 0; i < wordDict.size(); i++){
            set.insert(wordDict[i]);
        }
        int array = new int[s.size()];
        for(unsigned i = 0; i < s.size(); i++){

        }
    }
};
