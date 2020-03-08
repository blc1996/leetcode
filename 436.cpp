class Solution {
public:
    struct pair_hash
    {
        template <class T1, class T2>
        std::size_t operator() (const std::pair<T1, T2> &pair) const
        {
            return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
        }
    };
    
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        unordered_map<pair<int, int>, int, pair_hash> indexMap;
        for(int i = 0; i < intervals.size(); i++){
            indexMap.insert({pair<int, int>(intervals[i][0], intervals[i][1]), i});
        }

        auto comp = [](const vector<int>& i1, const vector<int>& i2){ return i1[0] < i2[0]; };
        sort(intervals.begin(), intervals.end(), comp);

        int length = intervals.size();
        vector<int> res(length, -1);
        for (int i = 0; i < length; i++) {
            int left = i + 1, right = length - 1;
            int tempVal = intervals[i][1];
            if(intervals[right][0] < tempVal){
                continue;
            }
            while(left <= right){
                int mid = (right - left) / 2 + left;
                if(intervals[mid][0] < tempVal){
                    left = mid + 1;
                }else{
                    if(mid == i || intervals[mid - 1][0] < tempVal){
                        res[indexMap[pair<int, int>(intervals[i][0], intervals[i][1])]] = indexMap[pair<int, int>(intervals[mid][0], intervals[mid][1])];
                        break;
                    }else{
                        right = mid - 1;
                    }
                }
            }
        }
        return res;
    }
};