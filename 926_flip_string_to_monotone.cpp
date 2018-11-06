/*
926. Flip String to Monotone Increasing My SubmissionsBack to Contest
User Accepted: 1200
User Tried: 1772
Total Accepted: 1224
Total Submissions: 3715
Difficulty: Medium
A string of '0's and '1's is monotone increasing if it consists of some number of '0's (possibly 0), followed by some number of '1's (also possibly 0.)

We are given a string S of '0's and '1's, and we may flip any '0' to a '1' or a '1' to a '0'.

Return the minimum number of flips to make S monotone increasing.



Example 1:

Input: "00110"
Output: 1
Explanation: We flip the last digit to get 00111.
Example 2:

Input: "010110"
Output: 2
Explanation: We flip to get 011111, or alternatively 000111.
Example 3:

Input: "00011000"
Output: 2
Explanation: We flip to get 00000000.
 */

class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int num1 = 0, num0 = 0;
        int flag = 0, temp = 0;
        for(int i = 0; i < S.size(); i++){
            if(S[i] == '1'){
                if(temp == 0 && num1 <= num0){
                   num0 = num1;
                }
                flag = 1;
                temp++;
            }else if(flag == 1){
                num1 += temp;
                temp = 0;
                num0++;
            }
        }
        return num1 > num0 ? num0 : num1;
    }
};
