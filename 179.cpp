class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto cmp = [](const int& a, const int& b){
            if(a == 0) return false;
            string s1 = to_string(a);
            if(b == 0) return true;
            string s2 = to_string(b);
            int ptr1 = 0, ptr2 = 0;
            while(ptr1 < s1.size() || ptr2 < s2.size()){
                if(ptr1 >= s1.size()) ptr1 = 0;
                if(ptr2 >= s2.size()) ptr2 = 0;
                if(s1[ptr1] != s2[ptr2]){
                    return s1[ptr1] > s2[ptr2];
                }
                ptr1++;
                ptr2++;
            }
            return true;
        };
        sort(nums.begin(), nums.end(), cmp);
        string res;
        bool flag = false;
        for(int num : nums){
            if(!flag && num) flag = true;
            if(flag) res.append(to_string(num));
        }
        return res.size() ? res : "0";
    }
};