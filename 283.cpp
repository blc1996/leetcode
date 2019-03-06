class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[i] == 0){
                nums.erase(nums.begin() + i);
                count++;
            }
        }
        for(int i = 0; i < count; i++){
            nums.push_back(0);
        }
    }
};


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), r = 0, temp;

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                temp = nums[i];
                nums[i] = nums[r];
                nums[r++] = temp;
            }
        }
    }
};
