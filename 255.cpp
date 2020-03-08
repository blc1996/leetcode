class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int index = 0;
        return helper(preorder, index, INT_MIN, INT_MAX);
    }

    bool helper(vector<int>& preorder, int& index, int min, int max){
        int cur = index;
        if(cur >= preorder.size()){
            index--;
            return true;
        }
        if(preorder[cur] > max || preorder[cur] < min){
            index--;
            return false;
        }

        if(!helper(preorder, ++index, min, preorder[cur]) && !helper(preorder, ++index, preorder[cur], max))
            return false;
        return true;
    }
};


class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        return verifyPreorderCore(preorder, 0, preorder.size(), INT_MAX, INT_MIN);
    }
    
    bool verifyPreorderCore(vector<int>& preorder, int startIdx, int endIdx, int maxVal, int minVal){
        if(startIdx == endIdx) return true;
        if(preorder[startIdx] < minVal || preorder[startIdx] > maxVal){
            return false;
        }else if(startIdx + 1 == endIdx){
            return true;
        }
        int nextIdx = startIdx + 1;
        while(nextIdx < endIdx && preorder[nextIdx] < preorder[startIdx]){
            nextIdx++;
        }
        return verifyPreorderCore(preorder, startIdx + 1, nextIdx, preorder[startIdx], minVal)
            && verifyPreorderCore(preorder, nextIdx, endIdx, maxVal, preorder[startIdx]);
    }
};



class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        return verifyPreorderCore(preorder, 0, preorder.size() - 1);
    }

    bool verifyPreorderCore(vector<int>& preorder, int left, int right){
        if(left >= right){
            return true;
        }
        bool flag = false;
        int tempIdx = right + 1;
        for(int i = left + 1; i <= right; i++){
            if(preorder[i] > preorder[left]){
                flag = true;
                tempIdx = i;
            }
            if(flag && preorder[i] < preorder[left]){
                return false;
            }
        }
        return verifyPreorderCore(preorder, left+1, tempIdx-1) && verifyPreorderCore(preorder, tempIdx, right);
    }
};