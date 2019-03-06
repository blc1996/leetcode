class Solution {
public:
    int characterReplacement(string s, int k) {
        int temp = helper(s, k, 0);
        return temp > s.size() ? s.size() : temp;
    }

    int helper(string& s, int k, int index){
        if(index >= s.size()){
            return k;
        }
        int i = index;
        while(i < s.size() && s[i] == s[index]){
            i++;
        }
        int j = i;
        int temp = k;
        for(; j < s.size() && temp > 0; temp--){
            j++;
            while(j < s.size() && s[j] == s[index]){
                j++;
            }
        }
        j--;
        return max(helper(s, k, i), max(j + 1 - index, i - index + k));
    }
};



class Solution {
public:
    int characterReplacement(string s, int k) {
        int res=0, maxCnt=0, start=0;
        vector<int> count(26,0);
        for(int i=0; i<s.length();i++)
        {
            maxCnt=max(maxCnt,++count[s[i]-'A']); 
            if(i-start+1-maxCnt>k)
            {
                --count[s[start]-'A'];
                start++;
            }
            else
                res=max(res,i-start+1);
        }
        return res;
    }
};