class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1, set2;
        vector<int> res;
        for(int i : nums1){
            set1.insert(i);
        }
        for(int i : nums2){
            if(set1.count(i) && set2.count(i) == 0){
                set2.insert(i);
                res.push_back(i);
            }
        }
        return res;
    }
};
