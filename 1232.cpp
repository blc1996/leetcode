class Solution {
public:
    int findBiggestCommonDivisor(int a, int b){
        int range = min(abs(a), abs(b));
        for(int i = range; i > 0; i--){
            if((a % i == 0) && (b % i) == 0){
                return i;
            }
        }
        return 1;
    }


    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int offsetX = coordinates[1][0] - coordinates[0][0], offsetY = coordinates[1][1] - coordinates[0][1];
        int commonDivisor = findBiggestCommonDivisor(offsetX, offsetY);
        offsetX /= commonDivisor;
        offsetY /= commonDivisor;

        bool flag = (offsetX > 0 && offsetY > 0) || (offsetX < 0 && offsetY < 0) ? true : false;
        
        // cout<<offsetX<<" "<<offsetY<<" "<<flag<<endl;
        if(offsetX == 0){
            int allX = coordinates[1][0];
            for(auto c : coordinates){
                if(c[0] != allX) return false;
            }
            return true;
        }
        if(offsetY == 0){
            int allY = coordinates[1][1];
            for(auto c : coordinates){
                if(c[1] != allY) return false;
            }
            return true;
        }

        for(int i = 2; i < coordinates.size(); i++){
            int tempX = (coordinates[i][0] - coordinates[0][0]);
            int tempY = (coordinates[i][1] - coordinates[0][1]);
            bool tempFlag = (tempX > 0 && tempY > 0) || (tempX < 0 && tempY < 0) ? true : false;
            
            if( (tempX / offsetX != tempY / offsetY) || (tempX % offsetX != 0) || (tempY % offsetY != 0) || (tempFlag != flag) ){
                // cout<<tempX<<" "<<tempY<<" "<<tempFlag<<endl;
                return false;
            }
        }
        return true;
    }
};