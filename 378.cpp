class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> current = matrix[0];
        vector<int> temp;
        bool flag = true;
        for(int i = 1; i < matrix.size(); i++){
            if(flag){
                mergeSort(temp, current, matrix[i]);
                flag = false;
                current.clear();
            }else{
                mergeSort(current, temp, matrix[i]);
                flag = true;
                temp.clear();
            }
               
        }
        return current.size() == 0 ? temp[k-1] : current[k-1];
    }

    void mergeSort(vector<int>& result, vector<int>& v1, vector<int>& v2){
        int left = 0, right = 0;
        while(left < v1.size() || right < v2.size()){
            if(left >= v1.size()){
                result.push_back(v2[right++]);
            }else if(right >= v2.size()){
                result.push_back(v1[left++]);
            }else{
                if(v1[left] > v2[right]){
                    result.push_back(v2[right++]);
                }else{
                    result.push_back(v1[left++]);
                }
            }
        }
    }
};