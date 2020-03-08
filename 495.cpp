class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int curTime = 0, res = 0;
        for(int i = 0; i < timeSeries.size(); i++){
            curTime = max(curTime, timeSeries[i]);
            res += duration - (curTime - timeSeries[i]);
            curTime = timeSeries[i] + duration;
        }
        return res;
    }
};