class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        stack<int> st;
        for(int i = 9; i > 0; i--){
            int temp = i;
            if(temp <= n)
                st.push(temp);
        }
        while(!st.empty()){
            int current = st.top();
            result.push_back(current);
            st.pop();
            for(int i = 9; i >= 0; i--){
                int temp = current * 10 + i;
                if(temp <= n)
                    st.push(temp);
            }
        }
        return result;
    }
};