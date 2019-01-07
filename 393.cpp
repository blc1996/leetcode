class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int index = 0;
        while(index < data.size()){
            int step = 0;
            while((data[index] >> (7 - step)) & 1 == 1){
                step++;
            }
            if(step == 0){
                step = 1;
            }
            if(step > 4 || index + step > data.size())
                return false;
            vector<int> temp;
            for(int i = 0; i < step; i++){
                temp.push_back(data[index + i]);
            }
            if(!helper(temp)){
                return false;
            }
            index += step;
        }
        return true;
    }

    bool helper(vector<int>& data){
        int bytes = data.size();
        for(int i = 0; i < bytes; i++){
            if(i == 0){
                if(bytes == 1)
                    bytes = 0;
                for(int j = 0; j < bytes; j++){
                    if(((data[0] >> (7 - j)) & 1) != 1){
                        return false;
                    }
                }
                if(((data[0] >> (7 - bytes)) & 1) != 0){
                    return false;
                }
            }else{
                if(((data[i] >> 7) & 1) != 1){
                    return false;
                }
                if(((data[i] >> 6) & 1) != 0){
                    return false;
                }
            }
        }
        return true;
    }
};