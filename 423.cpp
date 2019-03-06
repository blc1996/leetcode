class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char, int> map;
        int a[10] = {0};
        for(int i = 0; i < s.size(); i++){
            if(map.count(s[i]) == 0){
                map[s[i]] = 1;
            }else{
                map[s[i]] += 1;
            }
        }
        while(map['w'] != 0){
            a[2] ++;
            map['t'] -= 1;
            map['w'] -= 1;
            map['o'] -= 1;
        }
        while(map['x'] != 0){
            a[6] ++;
            map['s'] -= 1;
            map['i'] -= 1;
            map['x'] -= 1;
        }
        while(map['s'] != 0){
            a[7] ++;
            map['s'] -= 1;
            map['e'] -= 1;
            map['v'] -= 1;
            map['e'] -= 1;
            map['n'] -= 1;
        }
        while(map['z'] != 0){
            a[0] ++;
            map['z'] -= 1;
            map['e'] -= 1;
            map['r'] -= 1;
            map['o'] -= 1;
        }
        while(map['u'] != 0){
            cout<<"here";
            a[4] ++;
            map['f'] -= 1;
            map['o'] -= 1;
            map['u'] -= 1;
            map['r'] -= 1;
        }
        while(map['o'] != 0){
            a[1] ++;
            map['o'] -= 1;
            map['n'] -= 1;
            map['e'] -= 1;
        }
        while(map['r'] != 0){
            a[3] ++;
            map['t'] -= 1;
            map['h'] -= 1;
            map['r'] -= 1;
            map['e'] -= 2;
        }
        while(map['f'] != 0){
            a[5] ++;
            map['f'] -= 1;
            map['i'] -= 1;
            map['v'] -= 1;
            map['e'] -= 1;
        }
        while(map['g'] != 0){
            a[8] ++;
            map['e'] -= 1;
            map['i'] -= 1;
            map['g'] -= 1;
            map['h'] -= 1;
            map['t'] -= 1;
        }
        while(map['n'] != 0){
            a[9] ++;
            map['n'] -= 1;
            map['i'] -= 1;
            map['n'] -= 1;
            map['e'] -= 1;
        }
        string output;
        for(int i = 0; i < 10; i++){
            while(a[i]){
                output.push_back('0' + i);
                a[i]--;
            }
        }
        return output;
    }
};

