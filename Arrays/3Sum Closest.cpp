Given an integer array nums of length n and an integer target, find three integers at distinct indices in nums such that the sum is closest to target.
Return the sum of the three integers.
You may assume that each input would have exactly one solution.
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest_sum=INT_MAX/2;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    int sum=nums[i]+nums[j]+nums[k];
                    if(abs(sum-target) < abs(closest_sum-target)){
                        closest_sum=sum;
                    }
                }
            }
        }
        return closest_sum;
    }
};  
