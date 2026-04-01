Given an array arr[] which represents the dimensions of a sequence of matrices where the ith matrix has the dimensions (arr[i-1] x arr[i]) for i>=1, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.
// User function Template for C++

class Solution {
  public:
    int f(int i,int j,vector<int>&arr,vector<vector<int>>& dp){
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=INT_MAX;
        for(int k=i;k<=j-1;k++){
        int steps=f(i,k,arr,dp)+f(k+1,j,arr,dp)+arr[i-1]*arr[k]*arr[j];
         mini=min(mini,steps);
        }
        return dp[i][j]=mini;
    }
    int matrixMultiplication(vector<int> &arr) {
        int N=arr.size();
        vector<vector<int>> dp(N,vector<int>(N,-1));
        return f(1,N-1,arr,dp);
    }
};
