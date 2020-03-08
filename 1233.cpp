class Solution {
public:
    typedef struct folderNode{
        unordered_map<string, folderNode*> subFolders;
        bool isLeaf;
    }folderNode;

    vector<string> parseString(string s){
        vector<string> res;
        res.push_back("");
        s.push_back('/');
        int prev = 1;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == '/'){
                res.push_back(s.substr(prev, i - prev));
                i++;
                prev = i;
            }
        }
        return res;
    }

    void buildWithDir(const vector<string>& dir, folderNode* root){
        folderNode* curNode = root;
        for(int i = 1; i < dir.size(); i++){
            if(curNode->subFolders.count(dir[i]) == 0){
                curNode->subFolders.insert({dir[i], new folderNode()});
            }
            curNode = curNode->subFolders[dir[i]];
        }
        curNode->isLeaf = true;
    }

    bool check(const vector<string>& dir, folderNode* root){
        folderNode* curNode = root;
        for(int i = 1; i < dir.size(); i++){
            if(curNode->isLeaf) return false;
            curNode = curNode->subFolders[dir[i]];
        }
        return true;
    }

    vector<string> removeSubfolders(vector<string>& folder) {
        folderNode* rootFolder = new folderNode();
        for(string s: folder){
            auto dir = parseString(s);
            buildWithDir(dir, rootFolder);
        }

        vector<string> res;
        for(string s : folder){
            auto dir = parseString(s);
            if(check(dir, rootFolder)) res.push_back(s);
        }
        return res;
    }
};