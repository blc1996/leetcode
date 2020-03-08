class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<pair<int, int>> numWithIdx;
        for(int i = 0; i < nums.size(); i++){
            numWithIdx.push_back(pair<int, int>(nums[i], i));
        }
        sort(numWithIdx.begin(), numWithIdx.end());
        int res = 0;
        for(int i = numWithIdx.size() - 1; i >= 0; i--){
            for(int j = 0; j < i; j++){
                if( (numWithIdx[j].first << 1) >= numWithIdx[i].first){
                    break;
                }else if(numWithIdx[j].second > numWithIdx[i].second){
                    res++;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    int mergeAndCount(vector<int>::iterator left, vector<int>::iterator right){
        if(right - left <= 1){
            return 0;
        }
        auto mid = (right - left) / 2 + left;
        int count = mergeAndCount(left, mid) + mergeAndCount(mid, right);
        for(auto i = left, j = mid; i != mid; i++){
            while(j != right && *i > 2L * *j){
                j++;
            }
            count += j - mid;
        }
        inplace_merge(left, mid, right);
        return count;
    }


    int reversePairs(vector<int>& nums) {
        return mergeAndCount(nums.begin(), nums.end());
    }
};