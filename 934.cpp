class Solution {
public:
    typedef pair<int, int> Pair;

    int paint(vector<vector<int>>& A, int i, int j) {
        if (i < 0 || j < 0 || i == A.size() || j == A.size() || A[i][j] != 1) return 0;
        A[i][j] = 2;
        return 1 + paint(A, i + 1, j) + paint(A, i - 1, j) + paint(A, i, j + 1) + paint(A, i, j - 1);
    }

    int shortestBridge(vector<vector<int>>& A) {
        if(A.size() == 0) return 0;
        int h = A.size(), w = A[0].size();
        for (int i = 0, found = 0; !found && i < A.size(); ++i)
            for (int j = 0; !found && j < A[0].size(); ++j) found = paint(A, i, j);

        queue<Pair> q;
        q.push(Pair(startX, startY));
        level.insert({Pair(startX, startY), 0});
        while(!q.empty()){
            auto curP = q.front();
            int curX = curP.first, curY = curP.second;
            q.pop();
            int curLevel = A[curX][curY];
            if(curX > 0 && A[curX - 1][curY] == 0){
                A[curX - 1][curY] = curLevel + 1;
                q.push(Pair(curX - 1, curY));
            }else if(A[curX - 1][curY] == 1){
                return curLevel - 2;
            }
            if(curY > 0 && A[curX][curY - 1] == 0){
                A[curX - 1][curY] = curLevel + 1;
                q.push(Pair(curX, curY - 1));
            }else if(A[curX][curY - 1] == 1){
                return curLevel - 2;
            }
            if(curX < h - 1 && A[curX + 1][curY] == 0){
                A[curX - 1][curY] = curLevel + 1;
                q.push(Pair(curX + 1, curY));
            }else if(A[curX + 1][curY] == 1){
                return curLevel - 2;
            }
            if(curY < w - 1 && A[curX][curY + 1] == 0){
                A[curX - 1][curY] = curLevel + 1;
                q.push(Pair(curX, curY + 1));
            }else if(A[curX][curY + 1] == 1){
                return curLevel - 2;
            }
        }
        return 0;
    }
};