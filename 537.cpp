class Solution {
public:
    int findIndex(const string& s){
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '+'){
                return i;
            }
        }
        return 0;
    }


    string complexNumberMultiply(string a, string b) {
        int indexA = findIndex(a), indexB = findIndex(b);
        int rNumA = stoi(a.substr(0, indexA)), rNumB = stoi(b.substr(0, indexB));
        int cNumA = stoi(a.substr(indexA + 1, a.size() - indexA - 2)), cNumB = stoi(b.substr(indexB + 1, b.size() - indexB - 2));
        int newReal = rNumA * rNumB - cNumA * cNumB;
        int newComplex = rNumA * cNumB + rNumB * cNumA;
        return to_string(newReal) + "+" + to_string(newComplex) + "i";
    }
};