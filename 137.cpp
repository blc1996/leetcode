class Solution {
public:
    int singleNumber(vector<int>& nums) {
        const int size = sizeof(int) * 8;
        char bit[size] = {0};
        for(unsigned i = 0; i < nums.size(); i++){
            for(unsigned j = 0; j < size; j++){
                int temp = nums[i] & (1 << j);
                if(temp != 0){
                     bit[j]++;
                    if(bit[j] == 3)
                        bit[j] = 0;
                }
            }
        }
        int res = 0;
        for(unsigned i = 0; i < size; i++){
            res += bit[i] << i;
        }
        return res;
    }
};
