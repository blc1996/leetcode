
// n^2 too slow
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        return mctFromLeafValuesCore(arr, 0, arr.size()).second;
    }

    pair<int, int> mctFromLeafValuesCore(vector<int>& v, int startIdx, int endIdx){
        int n = v.size();
        if(n == 1){
            return pair<int, int>(v[0], 0);
        }else if(n == 2){
            return pair<int, int>(max(v[0], v[1]), v[0] * v[1]);
        }
        int minSum = INT_MAX, maxLeafNode = 0;
        for(int i = startIdx; i < endIdx; i++){
            auto leftTemp = mctFromLeafValuesCore(v, startIdx, startIdx + i);
            auto rightTemp = mctFromLeafValuesCore(v, startIdx + i, endIdx);
            int curSum = leftTemp.second + rightTemp.second + leftTemp.first * rightTemp.first;
            // cout<<curSum<<" "<<leftTemp.first<<" "<<leftTemp.second<<" "<<rightTemp.first<<" "<<rightTemp.second<<" "<<v.size()<<" "<<i<<endl;
            if(curSum < minSum){
                minSum = curSum;
                maxLeafNode = max(leftTemp.first, rightTemp.first);
            }
        }
        return pair<int, int>(maxLeafNode, minSum);
    }
};

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        vector<vector<pair<int, int>>> store(arr.size() + 1, vector<pair<int, int>>(arr.size() + 1, pair<int, int>(-1, -1)));
        return mctFromLeafValuesCore(arr, 0, arr.size()).second;
    }

    pair<int, int> mctFromLeafValuesCore(vector<vector<int>>& store, vector<int>& v, int startIdx, int endIdx){
        int n = endIdx - startIdx;
        if(n == 1){
            return pair<int, int>(v[startIdx], 0);
        }else if(n == 2){
            return pair<int, int>(max(v[startIdx], v[startIdx+1]), v[startIdx] * v[startIdx+1]);
        }
        if(store[startIdx][endIdx].second == -1){
            int minSum = INT_MAX, maxLeafNode = 0;
            for(int i = 1; i < n; i++){
                auto leftTemp = mctFromLeafValuesCore(v, startIdx, startIdx + i);
                auto rightTemp = mctFromLeafValuesCore(v, startIdx + i, endIdx);
                int curSum = leftTemp.second + rightTemp.second + leftTemp.first * rightTemp.first;
                // cout<<curSum<<" "<<leftTemp.first<<" "<<leftTemp.second<<" "<<rightTemp.first<<" "<<rightTemp.second<<" "<<v.size()<<" "<<i<<endl;
                if(curSum < minSum){
                    minSum = curSum;
                    maxLeafNode = max(leftTemp.first, rightTemp.first);
                }
            }
            store[startIdx][endIdx] = pair<int, int>(maxLeafNode, minSum);
        }
        return store[startIdx][endIdx];
    }
};



// example
class Solution {
private:
	int FindNextUse(vector<int>& arr, vector<int>& use, int begin){
		for (int i = begin; i < arr.size();++i){
			if(use[i])
				return i;
		}
		return -1;
	}
public:
    int mctFromLeafValues(vector<int>& arr) {
        //将数组中相邻乘积最小的做乘法，计算结果给sum
		//然后将这两个合并为原来两个中较大的值
		int size = arr.size();
		vector<int> use(size, true);
		int ret = 0;
		for (int cnt = 1; cnt < size;++cnt){
			int min_l = -1, min_r = -1, min_product = INT_MAX;
			int l = -1, r = FindNextUse(arr, use, 0);
			while(1){
				l = r;
				r = FindNextUse(arr, use, r + 1);
				if(r==-1)
					break;
				int product = arr[l] * arr[r];
				if(product < min_product){
					min_l = l, min_r = r, min_product = product;
				}
			}
			ret += min_product;
			if(arr[min_l] < arr[min_r]){
				use[min_l] = false;
			}
			else{
				use[min_r] = false;
			}
		}
		return ret;
	}
};

int mctFromLeafValues(vector<int>& A) {
    int res = 0, n = A.size();
    vector<int> stack = {INT_MAX};
    for (int a : A) {
        while (stack.back() <= a) {
            int mid = stack.back();
            stack.pop_back();
            res += mid * min(stack.back(), a);
        }
        stack.push_back(a);
    }
    for (int i = 2; i < stack.size(); ++i) {
        res += stack[i] * stack[i - 1];
    }
    return res;
}