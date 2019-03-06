class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        for(int i = 0; i < 12; i++){
            for(int j = 0; j < 60; j++){
                if(num == checkDigit(i, j)){
                    if(j < 10){
                        result.push_back(to_string(i) + ":0" + to_string(j));
                    }else{
                        result.push_back(to_string(i) + ":" + to_string(j));
                    }
                }
            }
        }
        return result;
    }

    int checkDigit(int hour, int minute){
        int count = 0;
        for(int i = 0; i < 4; i++){
            if((hour >> i) & 1 == 1){
                count++;
            }
        }
        for(int i = 0; i < 6; i++){
            if((minute >> i) & 1 == 1){
                count++;
            }
        }
        return count;
    }
};