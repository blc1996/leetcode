class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        bool flag = false;
        vector<int> output;
        for(int i = 0; i < input.size(); i++){
            char cur = input[i];
            if(cur == '+' || cur == '-' || cur == '*'){
                flag = true;
                vector<int> res1 = diffWaysToCompute(input.substr(0, i));
                vector<int> res2 = diffWaysToCompute(input.substr(i+1, input.size()));
                for(int a : res1){
                    for(int b : res2){
                        if(cur == '+')
                            output.push_back(a+b);
                        else if(cur == '-')
                            output.push_back(a-b);
                        else
                            output.push_back(a*b);
                    }
                }
            }
        }
        if(!flag)
            return vector<int>(1, stoi(input));
        else
            return output;
    }
};
