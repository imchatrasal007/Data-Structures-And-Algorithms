Given an integer array arr[] and an integer k, your task is to find and return the kth smallest element in the given array.
class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int> pq ;
        for(int i = 0 ; i< arr.size() ; i++) {
            pq.push(arr[i]);
            if(pq.size() > k) pq.pop();
        }
        return pq.top() ;
    }
};
