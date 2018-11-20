class Solution {
public:
    void reverseWords(string &s) {
        vector<string> result = parse(s);
        string out;
        for(auto it = result.rbegin(); it != result.rend(); it++){
            if(out.size() > 0)
                out.append(" ");
            out.append(*it);
        }
        s = out;
    }

    vector<string> parse(string version){
        version.append(" ");
        vector<string> result;
        int ptr = 0, prev = 0;
        while(version[ptr] == ' ')
            ptr++;
        prev = ptr;
        while(ptr < version.size()){;
            if(version[ptr] == ' '){
                result.push_back(version.substr(prev, ptr - prev));
                while(version[ptr] == ' ')
                    ptr++;
                prev = ptr;
                continue;
            }
            ptr++;
        }
        return result;
    }
};
