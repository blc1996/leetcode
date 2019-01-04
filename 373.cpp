class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        multimap<int, pair<int, int>> mp;
        for(int i = 0; i < nums1.size(); i++){
            for(int j = 0; j < nums2.size(); j++){
                mp.insert({nums1[i] + nums2[j], pair<int, int>(nums1[i], nums2[j])});
            }
        }
        int count = 0, bound = min(k, (int)(nums1.size() * nums2.size()));
        vector<pair<int, int>> result;
        for(auto it = mp.begin(); it != mp.end() && count < bound; it++){
            count++;
            result.push_back(it->second);
        }
        return result;
    }
};

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> v;
        int temp1 = min(k, (int)nums1.size()), temp2 = min(k, (int)nums2.size());
        for(int i = 0; i < temp1; i++){
            for(int j = 0; j < temp2; j++){
                v.push_back(pair<int, int>(nums1[i], nums2[j]));
            }
        }
        int count = 0, bound = min(k, (int)(nums1.size() * nums2.size()));
        vector<pair<int, int>> result;
        for(; count < bound; count++){
            int idx = 0, sum = INT_MAX;
            for(int i = 0; i < v.size(); i++){
                if(v[i].first + v[i].second < sum){
                    sum = v[i].first + v[i].second;
                    idx = i;
                }
                result.push_back(v[idx]);
                v[idx].first = 0;
                v[idx].second = INT_MAX;
            }
        }
        return result;
    }
};

class Solution {
public:
    class mycomparison
    {
    public:
      bool operator() (const pair<int, int>& lhs, const pair<int, int>&rhs) const
      {
        return (lhs.first + lhs.second > rhs.first + rhs.second);
      }
    };

    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> q;
        int temp1 = min(k, (int)nums1.size()), temp2 = min(k, (int)nums2.size());
        for(int i = 0; i < temp1; i++){
            for(int j = 0; j < temp2; j++){
                q.push(pair<int, int>(nums1[i], nums2[j]));
            }
        }
        int count = 0, bound = min(k, (int)(nums1.size() * nums2.size()));
        vector<pair<int, int>> result;
        for(; count < bound; count++){
            result.push_back(q.top());
            q.pop();
        }
        return result;
    }
};
