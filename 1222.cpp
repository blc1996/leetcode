class Solution {
public:
    int calDist(const vector<int>& king, const vector<int>& queen){
        return abs(king[0] - queen[0]) + abs(king[1] - queen[1]);
    }


    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> store(8, vector<int>(2, -1));
        int x = king[0], y = king[1];
        for(auto q : queens){
            int qx = q[0], qy = q[1];
            int tempIdx = -1;
            if(qx == x && qy < y){
                tempIdx = 0;
            }else if(qx == x && qy > y){
                tempIdx = 1;
            }else if(qx > x && qy == y){
                tempIdx = 2;
            }else if(qx < x && qy == y){
                tempIdx = 3;
            }else if(qx - x == qy - y && qx - x > 0){
                tempIdx = 4;
            }else if(qx - x == qy - y && qx - x < 0){
                tempIdx = 5;
            }else if(qx - x == y - qy && qx - x > 0){
                tempIdx = 6;
            }else if(qx - x == y - qy && qx - x < 0){
                tempIdx = 7;
            }
            if(tempIdx != -1){
                if(store[tempIdx][0] == -1 || (calDist(king, q) < calDist(king, store[tempIdx]))){
                    store[tempIdx] = q;
                }
            }
        }
        vector<vector<int>> res;
        for(auto q : store){
            if(q[0] != -1) res.push_back(q);
        }
        return res;
    }
};