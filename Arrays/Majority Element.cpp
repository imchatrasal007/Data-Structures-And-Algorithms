Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
 class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count;
        int n=nums.size();
        int result;
        for(int i=0;i<n;i++){
          count=0;
          result=nums[i];
          for(int j=0;j<n;j++){
            if(result==nums[j]){
              count++;
            }
          }
          if(count>(n/2)){
            return result;
          }
        }
        map<int,int> mpp;
        int ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
          mpp[nums[i]]++;
        }
        for(auto it:mpp){
          if(it.second > n/2){
            ans=it.first;
          }
        }
        return ans;
    }
}; 
