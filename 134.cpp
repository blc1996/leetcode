/*
O(n^2)
 */
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.size() == 0)
            return 0;
        for(unsigned i = 0; i < gas.size(); i++){
            unsigned pos = i, index = gas.size();
            int sum = 0;
            while(index > 0 && sum >= 0){
                index--;
                sum += gas[pos] - cost[pos];
                pos = (pos + 1) % gas.size();
            }
            if(index == 0 && sum >= 0)
                return i;
        }
        return -1;
    }
};


/*
O(n)
 */
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(cost.size() == 0)
            return 0;
        int i = 0, j = gas.size() - 1;
        int sum = 0;
        bool flag = false;
        while(j >= i){
            if(!flag){
                sum += gas[i] - cost[i];
                i++;
                if(sum < 0)
                    flag = true;
            }else{
                sum += gas[j] - cost[j];
                j--;
                if(sum >= 0)
                    flag = false;
            }
        }
        if(sum >= 0)
            return (j + 1) % gas.size();
        return -1;
    }
};
