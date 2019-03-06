class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        for(int i = 0; i < nums.size(); i++){
            for(int j = 1; j < nums.size(); j++){
                if(nums[(i + j) % nums.size()] > nums[i]){
                    res[i] = nums[(i + j) % nums.size()];
                    break;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size = nums.size();
        std::vector<int> temp(size, -1);
        std::stack<int> st;
        for(int i=0; i<2*size; ++i)
        {
            int num = nums[i%size];
            while(!st.empty() && num>nums[st.top()])
            {
                temp[st.top()] = num;
                st.pop();
            }
            if(i<size)
                st.push(i);
        }

        return temp;
    }
};
