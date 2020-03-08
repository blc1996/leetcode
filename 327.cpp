class Solution {
public:
    int mergeCount(vector<long>& sum, int left, int right, int lower, int upper){
        if(right - left <= 1) return 0;
        int mid = (right + left) / 2;
        int sm = mid, gt = mid;
        int res = mergeCount(sum, left, mid, lower, upper) + mergeCount(sum, mid, right, lower, upper);
        for(int i = left; i < mid; i++){
            while(sm < right && sum[sm] - sum[i] < lower) sm++;
            while(gt < right && sum[gt] - sum[i] <= upper) gt++;
            res += gt - sm;
        }
        inplace_merge(sum.begin() + left, sum.begin() + mid, sum.begin() + right);
        return res;
    }


    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int l = nums.size();
        vector<long> sum(l + 1, 0);
        for(int i = 0; i < l; i++){
            sum[i + 1] = nums[i] + sum[i];
        }
        return mergeCount(sum, 0, l + 1, lower, upper);
    }
};