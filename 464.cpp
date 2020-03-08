class Solution {
public:
    char state[1 << 20] = {0};

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger >= desiredTotal)
            return true;
        int sum = (1 + maxChoosableInteger) * maxChoosableInteger / 2;
        if(sum < desiredTotal)
            return false;
        if(maxChoosableInteger == desiredTotal)
            return maxChoosableInteger % 2;
        return canIWinCore(0, maxChoosableInteger, desiredTotal);
    }

    bool canIWinCore(int options, int maxChoosableInteger, int desiredTotal){
        if(desiredTotal <= 0){
            return false;
        }else if(state[options]){
            return state[options] == 1;
        }

        for(int i = 0; i < maxChoosableInteger; i++){
            if( !(options & 1<<i) && !canIWinCore(options | 1<<i, maxChoosableInteger, desiredTotal - i - 1))
                return state[options] = 1;
        }
        state[options] = -1;
        return false;
    }
};