class Solution {
public:
    class mycomparison
    {
    public:
        
      bool operator() (const vector<int>& a, const vector<int>& b) const
      {
        int distA = a[0] * a[0] + a[1] * a[1], distB = b[0] * b[0] + b[1] * b[1];
        return distA < distB;
      }
    };
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        priority_queue<vector<int>, vector<vector<int>>, mycomparison> pq;
        for(auto p : points){
            if(pq.size() < K){
                pq.push(p);
            }else{
                auto a = pq.top();
                int distA = a[0] * a[0] + a[1] * a[1], distB = p[0] * p[0] + p[1] * p[1];
                if(distA > distB){
                    pq.pop();
                    pq.push(p);
                }
            }
        }
        while(!pq.empty()){
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};