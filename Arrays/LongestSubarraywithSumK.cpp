Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value k. If there is no subarray with sum equal to k, return 0.
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
         unordered_map<int,int> preSumMap;
         int maxlen=0;
         int sum=0;
         for(int i=0;i<N;i++)
         {
             sum+=A[i];
             if(sum==K)
             {
                 maxlen=max(maxlen,i+1);
             }
             int rem=sum-K;
             if(preSumMap.find(rem)!=preSumMap.end())
             {
                 int len=i-preSumMap[rem];
                 maxlen=max(maxlen,len);
             }
             if(preSumMap.find(sum)==preSumMap.end())
             {
             preSumMap[sum]=i;
             }
         }
         return maxlen;
    } 

};
  
