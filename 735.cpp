class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i : asteroids){
            if(i > 0){
                st.push(i);
            }else{
                if(st.empty()){
                    st.push(i);
                }else{
                    while(!st.empty() && st.top() > 0 && st.top() < abs(i)){
                        st.pop();
                    }
                    if(st.empty() || st.top() < 0){
                        st.push(i);
                    }else if(st.top() == abs(i)){
                        st.pop();
                    }
                }
            }
        }
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};