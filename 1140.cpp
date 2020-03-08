class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        vector<vector<int>> dp(piles.size(), vector<int>(piles.size() + 1, 0));

    }

    bool stoneGameIICore(const vector<int>& piles, int start, bool side, vector<vector<int>>& dp){
        if(start >= piles.size()){
            return remain > 0;
        }
    }
};