class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        if(T.size() == 0) return vector<int>();
        stack<pair<int, int>> st;
        st.push(pair<int, int>(T[0], 0));
        vector<int> res(T.size(), 0);
        for(int i = 1; i < T.size(); i++){
            while(!st.empty() && T[i] > st.top().first){
                auto temp = st.top().second;
                st.pop();
                res[temp] = i - temp;
            }
            st.push(pair<int, int>(T[i], i));
        }
        return res;
    }
};