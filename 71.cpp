class Solution {
public:
    string simplifyPath(string path) {
        int idx = 0, left = 0;
        stack<int> st;
        string result;
        if(path[path.size() - 1] != '/')
            path += '/';
        while(idx < path.size()){
            if(path[idx] == '/'){
                if(idx != left){
                    st.push(idx - left);
                    result += path.substr(left, st.top());
                }
                while(idx < path.size() && path[idx] == '/')
                    idx++;
                left = idx - 1;
            }else if(path[idx] == '.' && path[idx + 1] == '/'){
                idx += 1;
                while(idx < path.size() && path[idx] == '/')
                    idx++;
                left = idx - 1;
            }else if(path[idx] == '.' && path[idx + 1] == '.'){
                if(idx + 2 < path.size() && path[idx + 2] != '/'){
                    idx = idx +3;
                    continue;
                }
                if(!st.empty()){
                    result.erase(result.size() - st.top(), st.top());
                    st.pop();
                }
                idx += 2;
                while(idx < path.size() && path[idx] == '/')
                    idx++;
                left = idx - 1;
            }else{
                idx++;
            }
        }
        if(result.size() == 0)
            result += "/";
        return result;
    }
};
