class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;

        int start = 0, end = 0, longest = 0;
        while(end < s.length()){
            if(m.count(s.at(end)) == 0){
                m[s.at(end)] = end;
                end++;
            }else{
                longest = (end - start) > longest ? (end - start) : longest;
                start = m[s.at(end)] + 1;
                end = start;
                m.clear();
            }
        }
        longest = (end - start) > longest ? (end - start) : longest;
        return longest;
    }
};
/*
array
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int array[256];
        memset(array, -1, 256*sizeof(int));

        int start = 0, end = 0, longest = 0;
        while(end < s.length()){
            if(array[s.at(end)] == -1){
                array[s.at(end)] = end;
                end++;
            }else{
                longest = (end - start) > longest ? (end - start) : longest;
                start = array[s.at(end)] + 1;
                end = start;
                memset(array, -1, 256*sizeof(int));
            }
        }
        longest = (end - start) > longest ? (end - start) : longest;
        return longest;
    }
};
