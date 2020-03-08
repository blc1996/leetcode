class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_map<int, int> mp;
        for(int i : candies){
            mp[i]++;
        }
        int sum = candies.size(), kind = mp.size(), minOdd = INT_MAX;
        for(auto it = mp.begin(); it != mp.end(); it++){
            if(it->second % 2 == 0){
                minOdd = min(minOdd, it->second);
            }
        }
        if(sum % 2){
            kind--;
            sum -= minOdd;
        }
        return min(sum / 2, kind);
    }
};