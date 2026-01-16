You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock.
Find and return the maximum profit you can achieve
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        if(n==0) return 0;
        dp[n][0]=dp[n][1]=0;
        int profit;
          for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            if (buy == 0) { 
                profit = max(0 + dp[ind + 1][0], -prices[ind] + dp[ind + 1][1]);
            }
            if (buy == 1) {
                profit = max(0 + dp[ind + 1][1], prices[ind] + dp[ind + 1][0]);
            }
            dp[ind][buy] = profit;
        }
    }
    return dp[0][0];
    }
};
