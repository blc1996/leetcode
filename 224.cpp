class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        st.push(1);
        st.push(0);
        int sign = 1; //1: add; -1: minus
        int temp = 0, cache = 0;
        s.push_back(')');
        for(unsigned i = 0; i < s.size(); i++){
            if(s[i] == ' ')
                continue;
            if(s[i] == '('){
                st.push(sign);
                st.push(cache);
                cache = 0;
                sign = 1;
            }else if(s[i] == ')'){
                cache += sign * temp;
                temp = 0;
                int prevNum = st.top();
                st.pop();
                cache = prevNum + st.top() * cache;
                st.pop();
            }else if(s[i] >='0' && s[i] <= '9'){
                temp = temp*10 + s[i] - '0';
            }else{
                cache += sign * temp;
                temp = 0;
                sign = s[i] == '+' ? 1 : -1;
            }
        }
        return cache;
    }
};
