class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.size() < k)
            return 0;
        unordered_map<char, vector<int>> mp;
        vector<int> seperate;
        for(int i = 0; i < s.size(); i++){
            if(mp.count(s[i]) == 0)
                mp.insert({s[i], vector<int>()});
            mp[s[i]].push_back(i);
        }
        bool flag = true;
        for(char c = 'a'; c <= 'z'; c++){
            if(mp.count(c) != 0){
                if(mp[c].size() < k){
                    flag = false;
                    for(int i = 0; i < mp[c].size(); i++)
                        seperate.push_back(mp[c][i]);
                }
            }
        }
        if(flag)
            return s.size();
        seperate.push_back(-1);
        seperate.push_back(s.size());
        sort(seperate.begin(), seperate.end());
        int max = 0;
        for(int i = 1; i < seperate.size(); i++){
            int temp = longestSubstring(s.substr(seperate[i-1] + 1, seperate[i] - seperate[i-1] - 1), k);
            max = temp > max ? temp : max;
        }
        return max;
    }
};

//this one is too slow
class Solution {
public:
    int longestSubstring(string s, int k) {
        return helper(s, 0, k.size(), k);
    }

    int helper(string& s, int front, int back, int k){
        if(back - front < k)
            return 0;
        unordered_map<char, vector<int>> mp;
        for(int i = front; i < back; i++){
            if(mp.count(s[i]) == 0)
                mp.insert({s[i], vector<int>()});
            mp[s[i]].push_back(i);
        }
        bool flag = true;
        for(char c = 'a'; c <= 'z'; c++){
            if(mp.count(c) != 0){
                if(mp[c].size() < k){
                    flag = false;
                    break;
                }
            }
        }
        if(flag)
            return back - front;
        else{
            return max(helper(s, front + 1, back, k), helper(front, back - 1, k));
        }
    }
};
