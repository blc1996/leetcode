class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> mp;
        for(auto v : intervals){
            mp[v[0]]++;
            mp[v[1]]--;
        }
        int res = 0, count = 0;
        for(auto it = mp.begin(); it != mp.end(); it++){
            count += it->second;
            res = max(res, count);
        }
        return res;
    }
};