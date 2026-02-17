Given an array arr[] of distinct elements, which was initially sorted in ascending order but then rotated at some unknown pivot, the task is to find the index of a target key.  If the key is not present in the array, return -1.
class Solution {
  public:
    int search(int A[], int l, int h, int target) {
        int left,right,mid;
        left=0,right=h;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(target==A[mid])
            {
                return mid;
            }
            if(A[left]<=A[mid])
            {
                if(A[left]<=target && target<=A[mid])
                {
                   right=mid-1;
                }
                else
                {
                    left=mid+1;
                }
            }
            else
            {
                if(A[mid]<=target && target<=A[right])
                {
                   left=mid+1;
                }
                else
                {
                    right=mid-1;
                }

            }
        }
        return -1;
    }
};
