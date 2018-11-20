class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 0)
            return 0;
        priority_queue<int> result;
        return result.top();
    }

    void helper(vector<vector<int>>& triangle, int level, int index, int sum, priority_queue<int>& result){
        if(level == triangle.size()){
            result.push(sum + triangle[level - 1][index]);
            return;
        }

        helper(triangle,level + 1, index, sum + triangle[level - 1][index], result);
        helper(triangle,level + 1, index + 1, sum + triangle[level - 1][index], result);
    }
};


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 0)
            return 0;
        int array[triangle.size()];
        array[0] = triangle[0][0];
        for(int i = 1; i < triangle.size(); i++){
            array[i] = array[i - 1] + triangle[i][i];
            for(int j = i - 1; j > 0; j--){
                array[j] = min(array[j], array[j - 1]) + triangle[i][j];
            }
            array[0] = array[0] + triangle[i][0];
        }
        int min = array[0];
        for(int i = 1; i < triangle.size(); i++){
            if(array[i] < min)
                min = array[i];
        }
        return min;
    }
};
