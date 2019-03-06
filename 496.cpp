class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        unordered_map<int, int> map;
        stack<int> st;
        for(int i : nums){
            while(!st.empty() && i > st.top()){
                map[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        vector<int> ans;
        for(int i : findNums){
            if(map.count(i)){
                ans.push_back(map[i]);
            }else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
