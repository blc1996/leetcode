class Solution {
public:
    static bool func(const pair<int,int> &a, const pair<int,int> &b){
        return (a.second < b.second);
    }

    static bool func2(const pair<int,int> &a, const pair<int,int> &b){
        return (a.first > b.first);
    }

    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        if(people.size() == 0){
            return people;
        }
        stable_sort(people.begin(), people.end(), func);
        stable_sort(people.begin(), people.end(), func2);
        vector<pair<int, int>> result;
        result.push_back(people[0]);
        for(int i = 1; i < people.size(); i++){
            if(people[i].second == 0){
                result.insert(result.begin(), people[i]);
                continue;
            }
            int count = 0;
            bool flag = false;
            for(int j = 0; j < result.size(); j++){
                if(result[j].first >= people[i].first){
                    count++;
                }
                if(count == people[i].second){
                    result.insert(result.begin() + j + 1, people[i]);
                    flag = true;
                    continue;
                }
            }
            if(!flag){
                result.push_back(people[i]);
            }
        }
        return result;
    }
};
