class Solution {
public:
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        unordered_set<string> set;
        int res = 0;
        for(int i = 0; i < n; i++){
            int maxLength = n - i;
            for(int j  = 1; j < maxLength; j++){
                string tempStr = tile.substr(i, j);
                if(!set.count(tempStr)){
                    res++;
                    set.insert(tempStr);
                }
            }
        }
        return res;
    }
};