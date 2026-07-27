class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int profit = 0;
        int maxProfit = profit;

        for(int i = 1; i < prices.size();i++){
          profit = prices[i] - buy;
          if(profit > maxProfit)
          {
            maxProfit = profit;
          }
          if(prices[i] < buy)
          {
            buy = prices[i];
          }
          
        }
        return maxProfit;
    }
};