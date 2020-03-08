class Solution {
public:
    pair<int, int> parseTime(const string& s){
        int i = 0;
        while(s[i] != ':') i++;
        return pair<int, int>(stoi(s.substr(0, i)), stoi(s.substr(i + 1)));
    }

    int findMinDifferenceCore(const string& timePoints1, const string& timePoints2) {
        auto time1 = parseTime(timePoints1);
        auto time2 = parseTime(timePoints2);
        int res = 0;
        res += ((time2.first + 24 - time1.first) % 24) * 60;
        res += time2.second - time1.second;
        res = abs(res);
        return res > 720 ? 1440 - res : res;
    }

    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int res = 1440;
        for(int i = 0; i < timePoints.size(); i++){
            res = min(res, findMinDifferenceCore(timePoints[i], timePoints[(i+1) % timePoints.size()]));
        }
        return res;
    }
};