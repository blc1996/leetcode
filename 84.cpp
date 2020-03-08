class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.push_back(0);
        int n = heights.size();
        int ret = 0;
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                int h = heights[st.top()];
                st.pop();
                int idx = st.empty() ? -1 : st.top();
                ret = max(ret, h * (i - idx - 1));
            }
            st.push(i);
        }
        return ret;
    }
};