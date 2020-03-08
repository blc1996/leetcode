class Solution {
public:
    class dictNode{
    public:
        char c;
        bool isEnd;
        vector<dictNode *> childrens;

        dictNode(char character, bool end){
            c = character;
            isEnd = end;
            childrens = vector<dictNode *>();
        }
    };
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        
    }
};