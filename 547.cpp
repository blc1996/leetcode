class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int res = 0, studentNum = M.size();
        unordered_set<int> set;
        for(int i = 0; i < studentNum; i++){
            if(set.count(i)) continue;
            res++;
            queue<int> q;
            q.push(i);
            set.insert(i);
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                for(int j = 0; j < studentNum; j++){
                    if(M[cur][j] && !set.count(j)){
                        set.insert(j);
                        q.push(j);
                    }
                }
            }
        }
        return res;
    }
};