class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int index = 0;
        int maxP = 0;
        for(unsigned i = 0; i < prices.size(); i++){
            if(prices[i] < prices[index]){
                index = i;
            }else{
                maxP = max(maxP, prices[i] - prices[index]);
            }
        }
        return maxP;
    }
};
