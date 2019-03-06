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

