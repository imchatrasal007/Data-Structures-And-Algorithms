You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
You may assume that you have an infinite number of each kind of coin.
The answer is guaranteed to fit into a signed 32-bit integer.
class Solution {
public:
    int f(int amount,int ind,vector<int>&coins,vector<vector<int>> &dp){
        if(ind==0){
            return (amount%coins[0]==0);
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int notpick=f(amount,ind-1,coins,dp);
        int pick=0;
        if(coins[ind]<=amount) pick=f(amount-coins[ind],ind,coins,dp);
        return dp[ind][amount]=notpick+pick;
    }
    int change(int amount, vector<int>& coins) 
    {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return f(amount,n-1,coins,dp);
    }
};  
