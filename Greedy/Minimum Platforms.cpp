Given arrival arr[] and departure dep[] times of trains on the same day, find the minimum number of platforms needed so that no train waits. A platform cannot serve two trains at the same time; if a train arrives before another departs, an extra platform is needed.
class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int count=0;
        int ans=0;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int i=0,j=0;
        while(i<n && j<n){
            if(arr[i]<=dep[j]){
                count++;
                i++;
            }
            else{
                count--;
                j++;
            }
            ans=max(ans,count);
        }
        return ans;
    }
};
  
