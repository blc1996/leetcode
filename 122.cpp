class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        int index = 0;
        int maxP = 0;
        for(unsigned i = 0; i < prices.size() - 1; i++){
            if(prices[i] < prices[index]){
                index = i;
                continue;
            }
            if(prices[i] < prices[i + 1]){
                continue;
            }else{
                maxP += prices[i] - prices[index];
                index = i + 1;
            }
        }
        if(prices[prices.size() - 1] > prices[index])
            maxP += prices[prices.size() - 1] - prices[index];
        return maxP;
    }
};
