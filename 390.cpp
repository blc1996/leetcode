class Solution {
public:
    int lastRemaining(int n) {
        vector<int> v(n, 0);
        for(int i = 0; i < n; i++){
            v[i] = i+1;
        }
        int size = n;
        bool right = true;
        while(size > 0){
            if(size == 1){
                return v[0];
            }
            // for(int i = 0; i < size; i++)
            //     cout<<v[i]<<" ";
            // cout<<endl;
            int num = size / 2;
            if(right){
                for(int i = 1; i < size; i += 2){
                    v[i/2] = v[i];
                }
                right = false;
            }else{
                int i = ((size % 2) == 0) ? 0 : 1;
                for(; i < size; i += 2){
                    v[i/2] = v[i];
                }
                right = true;
            }
            size = num;
        }
        return 0;
    }
};

class Solution {
public:
    int lastRemaining(int n) {
        if(n == 1)
            return 1;
        int left = 2, right = ((n % 2) == 0) ? n : n-1;
        bool flag = false;
        int count = 2;
        n /= 2;
        while(left <= right){
            // cout<<left<<" "<<right<<endl;
            if(left == right){
                return left;
            }
            if(flag){
                left += count;
                right = ((n % 2) == 0) ? right : right - count;
            }else{
                right -= count;
                left = ((n % 2) == 0) ? left : left + count;
            }
            flag = !flag;
            count *= 2;
            n /= 2;
        }
        return 0;
    }
};