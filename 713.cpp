class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        map<int, int>* store = new map<int, int>();
        int res = 0;
        for(int i : nums){
            map<int, int>* tempStore = new map<int, int>();
            if(i < k){
                tempStore->insert({i, 1});
                res++;
                for(auto it = store->begin(); it != store->end(); it++){
                    int curNum = it->first * i;
                    if(curNum < k){
                        (*tempStore)[curNum] += it->second;
                        res += it->second;
                    }else{
                        break;
                    }
                }
            }
            delete store;
            store = tempStore;
        }
        delete store;
        return res;
    }
};

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int windowLeft = 0, res = 0, currentProd = 1;
        for(int i = 0; i < nums.size(); i++){
            currentProd *= nums[i];
            while(currentProd >= k){
                currentProd /= nums[windowLeft++];
            }
            res += i - windowLeft + 1;
        }
        return res;
    }
};