class Solution {
public:
    void reverseString(vector<char>& s) {
        int repeat = s.size()/2;
        char temp;
        for(int i = 0; i < repeat; i++){
            temp = s[i];
            s[i] = s[s.size() - 1 - i];
            s[s.size() - 1 - i] = temp;
        }
    }
};

class Solution {
public:
    void reverseString(vector<char>& s) {
        int repeat = s.size()/2;
        for(int i = 0; i < repeat; i++){
            swap(s[i], s[s.size() - 1 - i]);
        }
    }
};


