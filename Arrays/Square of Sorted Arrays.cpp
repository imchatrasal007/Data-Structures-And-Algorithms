You are given an array you need to square the elements and return a resulting array.
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int i=0,j=n-1;
        for(int k=n-1;k>=0;k--){
          if( abs(nums[i]) < abs(nums[j]) ){
            ans[k]=nums[j]*nums[j];
            j--;
          }
          else{
            ans[k]=nums[i]*nums[i];
            i++;
          }
        }
        return ans;
    }
};
