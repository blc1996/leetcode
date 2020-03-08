class Solution {
public:
    vector<vector<int>> _rects;
    vector<int> _area;
    int _totalArea = 0;

    int calArea(vector<int>& rect){
        return abs(rect[0] - rect[2]) * abs(rect[1] - rect[3]);
    }


    Solution(vector<vector<int>>& rects) {
        _rects = rects;
        for(int i = 0; i < rects.size(); i++){
            _area.push_back(calArea(rects[i]));
            _totalArea += _area.back();
        }
    }
    
    vector<int> pick() {
        int randNum = ((double)rand() / RAND_MAX) * _totalArea;
        int i = 0;
        while(randNum >= _area[i]){
            randNum -= _area[i++];
        }
        int tempWidth = abs(_rects[i][0] - _rects[i][2]);
        int fac1 = _rects[i][0] < _rects[i][2] ? 1 : -1;
        int fac2 = _rects[i][1] < _rects[i][3] ? 1 : -1;
        return {_rects[i][0] + fac1 * (randNum % tempWidth), _rects[i][1] +  fac2 * (randNum / tempWidth)};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */