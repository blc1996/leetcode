class Solution {
public:
    Solution(vector<int> nums) {
        original = nums;
        size = nums.size();
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        // vector<bool> occupied(size, false);
        // vector<int> result(size, 0);
        // int count = 0;
        // while(count < size){
        //     int temp = rand() % size;
        //     while(occupied[temp] == true){
        //         temp = (temp + 1) % size;
        //     }
        //     occupied[temp] = true;
        //     result[temp] = original[count++];
        // }
        vector<int> temp = original;
        random_shuffle(temp.begin(), temp.end());
        return temp;
    }
private:
    int size;
    vector<int> original;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */


  vector<int> shuffle() {
        for (int i = 0; i < A.size(); i++) {
            int j = rand() % (i+1);
            int tmp = A[i]; A[i] = A[j]; A[j] = tmp;
        }
        return A;
    }