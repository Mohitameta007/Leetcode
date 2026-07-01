class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int profit = 0;
        int sum = 0;
        int index = 0;


        for(int i = 1 ; i < prices.size() ; i++)
        {
            if(prices[index] < prices[i])
            {
                profit = prices[i] - prices[index];
                maxprofit = max(maxprofit , profit);
            }
            else{
                index = i;
            }
            
        }
        return maxprofit;
    }
};