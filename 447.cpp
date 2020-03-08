class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        unordered_map<int, int> distMap;
        int length = points.size();
        int res = 0;
        for(int i = 0; i < length; i++){
            for(int j = 0; j < length; j++){
                int dist = getDistance(points[i], points[j]);
                if(!distMap.count(dist)){
                    distMap.insert({dist, 1});
                }else{
                    distMap[dist] = distMap[dist] + 1;
                }
            }
             for(auto it = distMap.begin(); it != distMap.end(); it++){
                res += it->second * (it->second - 1);
            }
            distMap.clear();
        }

        return res;
    }

    int getDistance(vector<int>& a, vector<int>& b){
        return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
    }
};