class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size() == 0)
            return vector<int>();
        vector<int> output;
        int num1 = 0, num2 = 0, cnt1 = 0, cnt2 = 0;
        for(int i : nums){
            if(num1 == i){
                cnt1++
            }else if(num2 == i){
                cnt2++;
            }else if(cnt1 == 0){
                num1 = i;
                cnt1 = 1;
            }else if(cnt2 == 0){
                num2 = i;
                cnt2 = 1;
            }else{
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0;
        cnt2 = 0;
        for(int i : nums){
            if(i == num1)
                cnt1++;
            else if(i == num2)
                cnt2++;
        }

        if(cnt1 > ((double)nums.size()) / 3)
            output.push_back(num1);
        if(cnt2 > ((double)nums.size()) / 3)
            output.push_back(num2);
        return output;
    }
};
