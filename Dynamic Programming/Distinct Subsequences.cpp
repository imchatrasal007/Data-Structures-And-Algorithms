Given two strings s and t, return the number of distinct subsequences of s which equals t.
The test cases are generated so that the answer fits on a 32-bit signed integer.
class Solution {
public:
    const int prime = 1e9 + 7;
    int numDistinct(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for (int i = 0; i <= n; i++) {
           dp[i][0] = 1;
        }
        for (int i = 1; i <= m; i++) {
          dp[0][i] = 0;
        }
        for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % prime;
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
       }
      return dp[n][m];
    }
};
