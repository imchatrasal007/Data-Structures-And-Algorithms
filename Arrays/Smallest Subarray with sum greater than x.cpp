Given a number x and an array of integers arr, find the smallest subarray with sum greater than the given value. If such a subarray do not exist return 0 in that case.
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
      int sum = 0;
      int ans = INT_MAX;
      int i = 0, j = 0;
      while (j < n)
      {
        sum += arr[j];
        while (sum > x)
        {
            ans = min(ans, j - i + 1);
            sum -= arr[i];
            i++;
        }
        j++;
      }
      return ans != INT_MAX ? ans : 0;
    }
};  
