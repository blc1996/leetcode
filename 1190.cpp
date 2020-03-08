class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        int n = s.size();
        string res(s);
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                st.push(res.size());
            }else if(s[i] == ')'){
                reverse(res.begin() + st.top(), res.end());
                st.pop();
            }else{
                res.push_back(s[i]);
            }
        }
        return res;
    }
};