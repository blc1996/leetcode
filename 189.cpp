class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k %= size;
        nums.insert(nums.begin(), nums.end() - k, nums.end());
        nums.erase(nums.begin() + size, nums.end());
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k %= size;
        vector<int> temp(size, 0);
        for(int i = size - k; i < size; i++)
            temp.push_back(nums[i]);
        for(int i = 0; i < size - k; i++)
            temp.push_back(nums[i]);
        nums = temp;
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k %= size;
        vector<int> temp(size, 0);
        for(int i = size - k; i < size; i++)
            temp[i - size + k] = nums[i];
        for(int i = 0; i < size - k; i++)
            temp[i + k] = nums[i];
        nums = temp;
    }
};
