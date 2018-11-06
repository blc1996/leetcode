/*

925. Long Pressed Name My SubmissionsBack to Contest
User Accepted: 2155
User Tried: 2354
Total Accepted: 2204
Total Submissions: 5130
Difficulty: Easy
Your friend is typing his name into a keyboard.  Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.

You examine the typed characters of the keyboard.  Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.



Example 1:

Input: name = "alex", typed = "aaleex"
Output: true
Explanation: 'a' and 'e' in 'alex' were long pressed.
Example 2:

Input: name = "saeed", typed = "ssaaedd"
Output: false
Explanation: 'e' must have been pressed twice, but it wasn't in the typed output.
Example 3:

Input: name = "leelee", typed = "lleeelee"
Output: true
Example 4:

Input: name = "laiden", typed = "laiden"
Output: true
Explanation: It's not necessary to long press any character.

 */


class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int count = 0;
        for(int i = 0; i < name.size(); i++){
            char c = name[i];
            if(c == typed[count++]){
                if(i == name.size() - 1 || c != name[i + 1]){
                    while(c == typed[count]){
                        count++;
                    }
                }
            }else{
                return false;
            }
        }
        if(count == typed.size())
            return true;
        else
            return false;
    }
};
