Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
 class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
       int n=nums.size();
       int l,r;
       l=0;
       r=0;
       int countZero=0;
       int maxi=INT_MIN;
       while(r<n){
         if(nums[r]==0) countZero++;
         if(countZero>k){
            if(nums[l]==0) countZero--;
            l++;
         }
         if(countZero<=k){
            maxi=max(maxi,r-l+1);
         }
         r++;
       }
       return maxi;
    }
}; 
