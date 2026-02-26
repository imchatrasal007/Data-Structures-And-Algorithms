Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).
class Solution {
public:
   bool func(int i,int j,string &s, string &p,vector<vector<int>> &dp){
     if(i<0&&j<0){
        return true;
     }
     if(i<0&&j>=0){
        return false;
     }
     if(i>=0&&j<0){
        for(int l=0;l<=i;l++){
            if(p[l]!='*'){
                return false;
            }
        }
        return true;
     }
     if(dp[i][j]!=-1){
        return dp[i][j];
     }

     if(p[i]==s[j]||p[i]=='?'){
         return dp[i][j]=func(i-1,j-1,s,p,dp);
     }
     if(p[i]=='*'){
        return dp[i][j]=func(i-1,j,s,p,dp)||func(i,j-1,s,p,dp);

     }
     return dp[i][j]=false;
   }
    bool isMatch(string s, string p) {
       vector<vector<int>> dp(p.size(),vector<int>(s.size(),-1));
       return func(p.size()-1,s.size()-1,s,p,dp);
    }
};
