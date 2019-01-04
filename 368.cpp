class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size() == 0)
            return vector<int>();
        sort(nums.begin(), nums.end());
        vector<vector<int>> temp(nums.size(), vector<int>());
        int idx = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < idx; j++){
                if((nums[i] % temp[j][temp[j].size() - 1] == 0)){
                    temp[j].push_back(nums[i]);
                }
            }
            temp[idx].push_back(nums[i]);
            idx++;
        }
        for(int i = nums.size() - 1; i >= 0; i--){
            for(int j = temp.size() - 1; j > i; j--){
                if((temp[j][0] % nums[i] == 0)){
                    temp[j].push_back(temp[j][0]);
                    temp[j][0] = nums[i];
                }
            }
        }
        int size = temp[0].size(), mark = 0;
        for(int i = 1; i < temp.size(); i++){
            if(temp[i].size() > size){
                size = temp[i].size();
                mark = i;
            }
        }
        return temp[mark];
    }
};
