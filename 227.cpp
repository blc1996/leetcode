class Solution {
public:
    int calculate(string s) {
        int a[3] = {1, 0, 0}; //0:sign 1:prev num 2: '*' or '/'
        int sign = 1; //1: add; -1: minus
        int temp = 0, cache = 0;
        s.push_back('+');
        s.push_back('+');
        for(unsigned i = 0; i < s.size(); i++){
            if(s[i] == ' ')
                continue;
            if(s[i] >='0' && s[i] <= '9'){
                temp = temp*10 + s[i] - '0';
            }else{
                if(a[2] != 0){
                    temp = a[2] == '*' ? a[1] * temp : a[1] / temp;
                    cout<<temp<<endl;
                    a[1] = 0;
                    a[2] = 0;
                }
                if(s[i] == '*' || s[i] == '/'){
                    cache += a[0] * a[1];
                    a[0] = sign;
                    a[1] = temp;
                    a[2] = s[i];
                    temp = 0;
                    continue;
                }
                cache += a[0] * a[1];
                a[0] = sign;
                a[1] = temp;
                temp = 0;
                sign = s[i] == '+' ? 1 : -1;
            }
        }
        return cache;
    }
};
