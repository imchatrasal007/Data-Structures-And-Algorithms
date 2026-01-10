Given two integers dividend and divisor. Find the quotient after dividing the dividend by divisor without using multiplication, division and mod operator.
Note: If the quotient is strictly greater than 2^31 - 1, return 2^31 - 1 and if the quotient is strictly less than -2^31, then return -2^31.
class Solution
{
    public:
    long long divide(long long dividend, long long divisor) 
    {
        long long sum=0;
        long long count=0;
        while(sum+dividend<=divisor)
        {
          sum+=dividend;
          count++;
        }
        return count;
    }
};  
