Given a string s, return the longest palindromic substring in s.
class Solution {
public:
    bool isPalindrome(string &s,int left,int right){
        while(left<right){
            if(s[left]!=s[right]){
                return false; 
            }
            left++;
            right--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n=s.size();
        string ans;
        int maxLen=1,start=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(s,i,j) && (j-i+1) >maxLen)
                {
                  start=i;
                  maxLen=j-i+1;
                }
            }
        }
        return s.substr(start,maxLen);
    }
};
 
