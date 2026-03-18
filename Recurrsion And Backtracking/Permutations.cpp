Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
 class Solution {
public:
void f(vector<int>&nums,vector<vector<int>> &ans,vector<int>&ds,int freq[],int ind,int   n)  {
            if(ds.size()==n){
                ans.push_back(ds);
                return;
            }
            for(int i=ind;i<n;i++){
              if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i]=1;
                f(nums,ans,ds,freq,ind,n);
                freq[i]=0;
                ds.pop_back();
              }
            }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n=nums.size();
        int freq[n];
        for(int i=0;i<n;i++){
          freq[i]=0;
        }
        f(nums,ans,ds,freq,0,n);
        return ans;
    }
}; 
