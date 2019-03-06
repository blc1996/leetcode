// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while(right > left){
            int index = left + (right - left)/2;
            if(isBadVersion(index)){
                right = index;
            }else{
                left = index + 1;
            }
        }
        return left;
    }
};
