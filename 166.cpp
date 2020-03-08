class Solution {
public:
    string fractionToDecimal(int numerator_int, int denominator_int) {
        if(numerator_int == 0){
            return "0";
        }
        string res = numerator_int < 0 ^ denominator_int < 0 ? "-" : "";
        long numerator = abs((long)numerator_int), denominator = abs((long)denominator_int);
        if(numerator < denominator){
            res.append("0.");
        }else{
            res.append(to_string(numerator / denominator));
            numerator %= denominator;
            if(numerator == 0){
                return res;
            }else{
                res.push_back('.');
            }
        }
        unordered_map<int, int> mp;
        string tempStr;
        int index = 0;
        while(numerator){
            if(mp.count(numerator)){
                tempStr.insert(tempStr.begin() + mp[numerator], '(');
                tempStr.push_back(')');
                break;
            }
            mp.insert({numerator, index});
            numerator *= 10;
            tempStr.push_back(numerator / denominator + '0');
            numerator %= denominator;
            index++;
        }
        res.append(tempStr);
        return res;
    }
};