Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int> arr(n+m,0);
        int l=0;
        int r=0;
        int index=0;
        while(l<n && r<m){
            if(nums1[l]<nums2[r]){
               arr[index]=nums1[l];
               l++;
               index++;
            }
            else{
                arr[index]=nums2[r];
                r++;
                index++;
            }
        }
        while(l<n){
            arr[index]=nums1[l];
            index++;
            l++;
        }
        while(r<m){
            arr[index]=nums2[r];
            index++;
            r++;
        }
        int ans=n+m;
         if (ans % 2 == 1) {
         return (double)arr[ans / 2];
         }
    double median = ((double)arr[ans / 2] + (double)arr[(ans / 2) - 1]) / 2.0;
         return median;

    }
};
