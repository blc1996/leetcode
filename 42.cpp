class Solution {
public:
    int trap(vector<int>& height) {
        map<int, vector<int> *> m;
        for(int i = 0; i < height.size(); i++){
            int j = height[i];
                if(m[j] == NULL){
                    m[j] = new vector<int>;
                }
                m[j]->push_back(i);
        }

        int count = 0, previous = 0;
        int maxIdx = 0, minIdx = height.size(), totalSize = 0;
        for(auto it = m.rbegin(); it != m.rend(); it++){
            if(previous != 0){
                if(previous - it->first > 1){
                    count += (previous - it->first - 1) * (maxIdx - minIdx - totalSize + 1);
                }
            }
            previous = it->first;
            vector<int> *temp = it->second;
            auto maxIt = max_element(temp->begin(), temp->end());
            auto minIt = min_element(temp->begin(), temp->end());
            totalSize += temp->size();
            maxIdx = max(maxIdx, *maxIt);
            minIdx = min(minIdx, *minIt);
            count += maxIdx - minIdx - totalSize + 1;
        }
        return count;
    }
};

