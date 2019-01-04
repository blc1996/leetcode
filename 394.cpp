class Solution {
public:
    string decodeString(string s) {
        if(s.size() == 0){
            return s;
        }
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != ']'){
                st.push(s[i]);
            }else{
                vector<char> temp;
                while(st.top() != '['){
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                int repeat = 0, count = 1;
                while(!st.empty() && (st.top() >= '0' && st.top() <= '9')){
                    cout<<repeat<<" "<<st.top()<<" "<<count<<endl;
                    repeat += count * (st.top() - '0');
                    count *= 10;
                    st.pop();
                }
                for(int j = 0; j < repeat; j++){
                    for(int k = temp.size() - 1; k >= 0; k--){
                        st.push(temp[k]);
                    }
                }
            }
        }
        string result;
        while(!st.empty()){
            result.insert(result.begin(), st.top());
            st.pop();
        }
        return result;
    }
};