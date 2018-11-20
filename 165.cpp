class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1 = parse(version1);
        vector<int> v2 = parse(version2);
        for(unsigned i = 0; i < v1.size() || i < v2.size(); i++){
            int t1 = i >= v1.size() ? 0 : v1[i];
            int t2 = i >= v2.size() ? 0 : v2[i];
            if(t1 < t2)
                return -1;
            else if(t1 > t2)
                return 1;
        }
        return 0;
    }

    vector<int> parse(string version){
        version.append(".");
        vector<int> result;
        int ptr = 0, prev = 0;
        while(ptr < version.size()){;
            if(version[ptr] == '.'){
                result.push_back(stoi(version.substr(prev, ptr - prev)));
                ptr++;
                prev = ptr;
                continue;
            }
            ptr++;
        }
        return result;
    }
};
