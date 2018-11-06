class Solution {
public:
    int numDecodings(string s) {
        if(s.size() <= 0) {return 0;}
        vector<int> nums(s.size()+1, 0);
        if(s[0] == '0') {return 0;}
        nums[0] = 1;nums[1] = 1;
        for(int i = 1; i<s.size(); i++) {
            if(s[i] == '0') {
                if(s[i-1] == '1' || s[i-1] == '2') {
                nums[i+1] = nums[i-1];
                } else {
                    return 0;
                }
            }
            else if(s[i-1] == '1') {
                nums[i+1] = nums[i]+nums[i-1];
            } else if(s[i-1] == '2') {
                if(s[i] <= '6') {
                    nums[i+1] = nums[i] + nums[i-1];
                } else{
                    nums[i+1] = nums[i];
                }
            } else{
                nums[i+1] = nums[i];
            }
            //cout << nums[i+1] << endl;
        }

        return nums[s.size()];
    }
};
