class Solution {
public:
    struct VectorHash {
        size_t operator()(const std::vector<int>& v) const {
            std::hash<int> hasher;
            size_t seed = 0;
            for (int i : v) {
                seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            }
            return seed;
        }
    };
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        unordered_set<vector<int>, VectorHash> s;
        vector<vector<int>> res;
        for(int i = nums.size() - 1; i >= 0; i--){
            int tempSize = res.size();
            for(int j = 0; j < tempSize; j++){
                const vector<int>& v = res[j];
                if(v[0] >= nums[i]){
                    vector<int> temp = vector<int>(v);
                    temp.insert(temp.begin(), nums[i]);
                    if(!s.count(temp)){
                        res.push_back(temp);
                        s.insert(temp);
                    }
                }
            }

            for(int j = i + 1; j < nums.size(); j++){
                if(nums[j] >= nums[i]){
                    vector<int> temp = {nums[i], nums[j]};
                    if(!s.count(temp)){
                        res.push_back(temp);
                        s.insert(temp);
                    }
                }
            }
        }
        return res;
    }
};


// better solution
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> seq;
        dfs(res, seq, nums, 0);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<int>& seq, vector<int>& nums, int pos) {
        if(seq.size() > 1) res.push_back(seq);
        unordered_set<int> hash;
        for(int i = pos; i < nums.size(); ++i) {
            if((seq.empty() || nums[i] >= seq.back()) && hash.find(nums[i]) == hash.end()) {
                seq.push_back(nums[i]);
                dfs(res, seq, nums, i + 1);
                seq.pop_back();
                hash.insert(nums[i]);
            }
        }
    }
};