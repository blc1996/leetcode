class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> res(nums.size(), "");
        vector<pair<int, int>> v;
        for(int i = 0; i < nums.size(); i++){
            v.push_back(pair<int, int>(nums[i], i));
        }
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        for(int i = 0; i < v.size(); i++){
            if(i == 0){
                res[v[i].second] = "Gold Medal";
            }else if(i == 1){
                res[v[i].second] = "Silver Medal";
            }else if(i == 2){
                res[v[i].second] = "Bronze Medal";
            }else{
                res[v[i].second] = to_string(i + 1);
            }
        }
        return res;
    }
};