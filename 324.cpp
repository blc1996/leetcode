class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){

        }
    }

    int findMedian(vector<int>& nums) {
        int mid = nums.size() / 2;
        int tempMidNum = nums[mid];
        swap(nums[nums.size() - 1], nums[mid]);
        int left = 0, right = nums.size() - 2;
        for(int i = 0; i < nums.size(); i++){

        }
    }
};


// quick select + 3-way partition