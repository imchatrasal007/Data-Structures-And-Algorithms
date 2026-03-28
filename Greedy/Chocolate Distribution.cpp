Given an array arr[] of positive integers, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are m students, the task is to distribute chocolate packets among m students such that -
i. Each student gets exactly one packet.
ii. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum and return that minimum possible difference.
class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
       int n=a.size();
       if(m>n) return -1;
       sort(a.begin(),a.end());
       int mini=INT_MAX;
       for(int i=0;i<=n-m;i++){
           int diff=a[i+m-1]-a[i];
            mini=min(mini,diff);
       }
       return mini;
    }
};  
