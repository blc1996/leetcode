class Solution {
public:
    int longestValidParentheses(string s) {
        int a[s.size() + 2];
        a[0] = 0;
        a[1] = 0;
        for(int i = 2; i <= s.size(); i++){
            int num = backValid(s.substr(0, i));
            a[i] = num > a[i-1] ? num : a[i-1];
        }
        return a[s.size()];
    }

    int backValid(const string s){
        stack<char> stack;
        int index = s.size() - 1;
        if(s[index] == '(')
            return 0;
        stack.push(s[index]);
        int temp = 0;
        int count = 0;
        while(index >= 0){
            index--;
            if(s[index] == ')'){
                stack.push(')');
            }else if(s[index] == '('){
                if(stack.empty()){
                    return count;
                }else{
                    stack.pop();
                    temp += 2;
                    if(stack.empty()){
                        count += temp;
                        temp = 0;
                    }
                }
            }
        }
        return count;
    }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() == 0){
            return 0;
        }
        vector<int> dp(s.size(), 0);
        for(int i = 1; i < s.size(); i++){
            if( dp[i - 1] < i && (s[i] == ')' && s[i - dp[i - 1] - 1] == '(') ){
                dp[i] = dp[i - 1] + 2;
            }
            int index = i;
            while(index >= 0 && dp[index]){
                index -= dp[index];
            }
            dp[i] = i - index;
        }
        return *max_element(dp.begin(), dp.end());
    }
};