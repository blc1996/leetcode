class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> output;
        set<vector<int>> s;

        for(int i = 1; i < 1<<n; i++){
            vector<int> temp;
            for(int j = 0; j < n; j++){
                if((i & (1 << j)) != 0){
                    temp.push_back(nums[j]);
                }
            }
            if(s.find(temp) == s.end()){
                output.push_back(temp);
                s.insert(temp);
            }
        }
        output.push_back({});

        return output;
    }
};
