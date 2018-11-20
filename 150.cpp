class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(unsigned i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+"){
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.pop();
                st.push(val1 + val2);
            }else if(tokens[i] == "-"){
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.pop();
                st.push(val2 - val1);
            }else if(tokens[i] == "*"){
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.pop();
                st.push(val1 * val2);
            }else if(tokens[i] == "/"){
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.pop();
                st.push(val2 / val1);
            }else{
                st.push(stoi(tokens[i]));
            }
           // cout<<tokens[i]<<" and "<<st.top()<<endl;
        }
        return st.top();
    }
};
