class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        vector<int> a(nums.size(), 0);
        if(nums[0] >= s)
            return 1;
        for(unsigned i = 1; i < nums.size(); i++){
            a[i] = a[i - 1];
            int sum = 0;
            int iter = (a[i] == 0) ? (i + 1) : (a[i-1] - 1);
            for(unsigned j = 0; j < iter; j++){
                sum += nums[i - j];
                if(sum >= s){
                    a[i] = j + 1;
                    break;
                }
            }
        }
        return a[nums.size() - 1];
    }
};


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums)
    {
        int n = nums.size();
        int ans = INT_MAX;
        int left = 0;
        int sum =0;
        for(int i =0;i<n;i++)
        {
            sum+=nums[i];
            while(sum >= s)
            {
                 ans = min(ans, i+1 - left);
                 sum-= nums[left++];
            }
        }



        return (ans!=INT_MAX) ? ans : 0;
    }
};
