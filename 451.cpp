class Solution {
public:
    string frequencySort(string s) {
        int freq[256] = {0};
        for(int i = 0; i < s.size(); i++){
            freq[s[i]]++;
        }
        priority_queue<pair<int, char>> pq;
        for(char i = 0; i < 256; i++){
            if(freq[i]){
                pq.push(pair<int, char>(freq[i], i));
            }
        }
        string res;
        while(!pq.empty()){
            auto elem = pq.top();
            pq.pop();
            for(int i = 0; i < elem.first; i++){
                res.push_back(elem.second);
            }
        }
        return res;
    }
};