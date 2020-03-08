class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        unordered_map<int, int> map;
        for(int i = 0; i < n; i++){
            map[nums[i]] = i;
        }
        vector<int> store(n, 0);
        for(int i = 0; i < n; i++){
            store[i] = i;
        }
        int res = -1;
        for(int i = 0; i < n; i++){
            if(map[nums[i]] == i && map.count(nums[i] + 1)){
                int indexLeft = map[nums[i]], indexRight = map[nums[i]+1];
                while(store[indexRight] != indexRight && store[indexRight] >= 0){
                    indexRight = store[indexRight];
                }
                if(store[indexRight] == indexRight){
                    store[indexRight] = -1;
                }
                if(store[indexLeft] < 0){
                    store[indexRight] += store[indexLeft];
                }else{
                    store[indexRight]--;
                }
                store[indexLeft] = indexRight;
                res = min(res, store[indexRight]);
            }
        }
        return -res;
    }
};