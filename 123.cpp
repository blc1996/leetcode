class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int buy1 = INT_MIN, buy2 = INT_MIN, sell1 = 0, sell2 = 0;
      for (int p : prices) {
        buy1 = max(buy1, -p);
        sell1 = max(sell1, buy1 + p);
        buy2 = max(buy2, sell1 - p);
        sell2 = max(sell2, buy2 + p);
      }
      return sell2;
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        int a[3][prices.size()];
        for(int i = 0; i < prices.size(); i++){
            a[0][i] = 0;
            a[1][i] = 0;
            a[2][i] = 0;
        }
        for(int i = 1; i < 3; i++){
            int minVal = prices[0];
            for(int j = 1; j < prices.size(); j++){
                minVal = min(minVal, prices[j] - a[i-1][j-1]);
                a[i][j] = max(a[i][j-1], prices[j] - minVal);
            }
        }
        return a[2][prices.size()-1];
    }
};
