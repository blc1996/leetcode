class Solution {
public:
    unordered_set<int> s;
    int nthUglyNumber(int n) {
        int count = 0, idx = 0;
        while(count < n){
            idx++;
            if(isUgly(idx)){
                s.insert(idx);
                count++;
            }
        }
        return idx;
    }

    bool isUgly(int num) {
        if(num == 0)
            return false;
        while(num % 2 == 0){
            if(s.count(num) != 0)
                return true;
            num /= 2;
        }
        while(num % 3 == 0){
            if(s.count(num) != 0)
                return true;
            num /= 3;
        }
        while(num % 5 == 0){
            if(s.count(num) != 0)
                return true;
            num /= 5;
        }
        if(num == 1)
            return true;
        else
            return false;
    }
};


struct Solution {
    int nthUglyNumber(int n) {
        vector <int> results (1,1);
        int i = 0, j = 0, k = 0;
        while (results.size() < n)
        {
            results.push_back(min(results[i] * 2, min(results[j] * 3, results[k] * 5)));
            if (results.back() == results[i] * 2) ++i;
            if (results.back() == results[j] * 3) ++j;
            if (results.back() == results[k] * 5) ++k;
        }
        return results.back();
    }
};
