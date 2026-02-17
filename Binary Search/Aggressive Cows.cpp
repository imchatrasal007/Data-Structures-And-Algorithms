You are given an array with unique elements of stalls[], which denote the positions of stalls. You are also given an integer k which denotes the number of aggressive cows. The task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible
// User function Template for C++
class Solution {
public:
    bool canwePlace(vector<int> &stalls,int dist,int cows)
    {
        int cntCows=1;
        int last=stalls[0];
        int i=1;
        int n=stalls.size();
        for(i=1;i<n;i++)
        {
            if(stalls[i]-last>=dist)
            {
                cntCows++;
                last=stalls[i];
            }
        
         if(cntCows>=cows) return true;
        }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) 
    {
        sort(stalls.begin(),stalls.end());
        int low=1;
        int high=stalls[n-1]-stalls[0];
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(canwePlace(stalls,mid,k)==true)
            low=mid+1;
            else
            high=mid-1;
        }
        return high;
    }
    
};
