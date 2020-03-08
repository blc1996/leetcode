class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        auto comp = [](const vector<int>& i1, const vector<int>& i2){ return i1[0] < i2[0]; };
        sort(points.begin(), points.end(), comp);
        int res = 0, pre = 0;
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] <= points[pre][1]) {
                res++;
                if (points[i][1] < points[pre][1]) pre = i;
            }
            else pre = i;
        }
        return points.size() - res;
    }
};