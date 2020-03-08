class Solution {
public:
    bool check(const unordered_map<char, int>& mp){
        for(auto it = mp.begin(); it != mp.end(); it++){
            if(it->second > 0) return false;
        }
        return true;
    }
    
    
    int getLength(const string& s,  unordered_map<char, int> mp, int size){
        int res = s.size();
        int left = 0, right = 0;
        while(right <= s.size()){
            if(check(mp)){
                // cout<<left<<" "<<right<<endl; 
                res = min(res, right - left);
                if(mp.count(s[left])){
                    mp[s[left]]++;
                }
                left++;
            }else{
                if(right == s.size()) return res;
                if(mp.count(s[right])){
                    mp[s[right]]--;
                }
                right++;
            }
        }
        return res;
    }

    int balancedString(string s) {
        unordered_map<char, int> mp;
        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
        }
        int balanceCount = s.size() / 4;
        unordered_map<char, int> redundant;
        int size = 0;
        for(auto it = mp.begin(); it != mp.end(); it++){
            if(it->second > balanceCount){
                redundant[it->first] = it->second - balanceCount;
                size += it->second - balanceCount;
            }
        }
        if(size == 0) return 0;
        int res = s.size();
        res = getLength(s, redundant, size);
        return res;
    }
};