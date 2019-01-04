class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, int> nameMap;
        int count = 0;
        for(int i = 0; i < equations.size(); i++){
            if(nameMap.count(equations[i].first) == 0)
                nameMap.insert({equations[i].first, count++});
            if(nameMap.count(equations[i].second) == 0)
                nameMap.insert({equations[i].second, count++});
        }
        vector<vector<double>> matrix(nameMap.size(), vector<double>(nameMap.size(), 0));
        for(int i = 0; i < equations.size(); i++){
            matrix[nameMap[equations[i].first]][nameMap[equations[i].second]] = values[i];
            matrix[nameMap[equations[i].second]][nameMap[equations[i].first]] = 1 / values[i];
        }
        vector<double> answer;
        for(int i = 0; i < queries.size(); i++){
            if(nameMap.count(queries[i].first) == 0 || nameMap.count(queries[i].second) == 0){
                answer.push_back(-1);
                continue;
            }
            if(queries[i].first == queries[i].second){
                answer.push_back(1);
            }else{
                int idx1 = nameMap[queries[i].first], idx2 = nameMap[queries[i].second];
                double temp = helper(idx1, idx2, -1, 1, matrix);
                if(temp != INT_MAX){
                    answer.push_back(temp);
                }else{
                    answer.push_back(-1);
                }
            }
        }
        return answer;
    }

    double helper(int start, int target, int prev, double prevValue, vector<vector<double>>& matrix){
        for(int j = 0; j < matrix.size(); j++){
            if(j == prev)
                continue;
            double value = matrix[start][j];
            if(value != 0){
                if(j == target)
                    return value * prevValue;
                else{
                    double temp = helper(j, target, start, value * prevValue, matrix);
                    if(temp != INT_MAX)
                        return temp;
                }
            }
        }
        return INT_MAX;
    }
};
