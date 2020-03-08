class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        map<int, int> mp;
        for(auto v : intervals){
            mp[v[0]]++;
            mp[v[1]]--;
        }
        int count = 0;
        for(auto it = mp.begin(); it != mp.end(); it++){
            count += it->second;
            if(count > 1) return false;
        }
        return true;
    }
};