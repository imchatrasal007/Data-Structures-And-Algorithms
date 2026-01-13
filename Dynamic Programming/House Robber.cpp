You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
class Solution {
public:
    int rob(vector<int>& arr) {
        vector<int> dp(arr.size(),-1);
         dp[0] = arr[0];
      for (int i = 1; i < arr.size(); i++) {
        int pick = arr[i];
        if (i > 1)
            pick += dp[i - 2];
        int nonPick = dp[i - 1];
        dp[i] = max(pick, nonPick);
     }
      return dp[arr.size() - 1];
    }
};  
  
