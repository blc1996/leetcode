class Solution {
public:
    bool isHappy(int n) {
        static unordered_set<int> s;
        if(n == 1){
            s.clear();
            return true;
        }

        if(s.count(n)){
            s.clear();
            return false;
        }
        s.insert(n);

        int newNum = 0;
        while(n > 0){
            int temp = n % 10;
            newNum += temp*temp;
            n /= 10;
        }
        return isHappy(newNum);
    }
};
