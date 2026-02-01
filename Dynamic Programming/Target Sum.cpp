You are given an integer array nums and an integer target.
You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.
class Solution {
public:
    int countPartitions(int n, int d, vector<int>& nums)
    {
      int sum = 0;
        for(auto it : nums) sum += it;
        
        if(sum - d < 0 || (sum - d) % 2) return 0;
        
        int k = (sum - d) / 2;
        
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        
        if(nums[0] == 0) dp[0][0] = 2;
        else dp[0][0] = 1;
        if(nums[0] != 0 && nums[0] <= k) dp[0][nums[0]] = 1;
        
        for(int ind=1; ind<n; ind++){
            
            for(int target=0; target<=k; target++){
            
                int notTake = dp[ind - 1][target];
            
                int take = 0;
                if(nums[ind] <= target) take = dp[ind - 1][target - nums[ind]];
                
                dp[ind][target] = (take + notTake);
                
            }
            
        }
        
        return dp[n - 1][k];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return countPartitions(n,target,nums);
    }
};  
