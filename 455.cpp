class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gIndex = 0;
        for(int i = 0; i < s.size(); i++){
            if(gIndex < g.size() && s[i] >= g[gIndex]){
                gIndex++;
            }
        }
        return gIndex;
    }
};