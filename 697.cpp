class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        unordered_map<int, vector<int>> map;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]].push_back(i);
        }
        int maxNum = 0, num = -1;
        for(auto it = map.begin(); it != map.end(); it++){
            vector<int>& temp = it->second;
            if(temp.size() > maxNum ||
                (temp.size() == maxNum &&
                (temp[temp.size()-1] - temp[0]) <
                (map[num].at(map[num].size() - 1) - map[num].at(0))
            )){
                maxNum = it->second.size();
                num = it->first;
            }
        }
        return map[num].at(map[num].size() - 1) - map[num].at(0) + 1;
    }
};

