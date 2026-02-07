Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
class Solution {
public:
  void dfs(int openP, int closeP, string s, int n, vector<string>& res) {
        if (openP == closeP && openP + closeP == n * 2) {
            res.push_back(s);
            return;
        }
        if (openP < n) {
            dfs(openP + 1, closeP, s + "(", n, res);
        }
        if (closeP < openP) {
            dfs(openP, closeP + 1, s + ")", n, res);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(0, 0, "", n, res);
        return res;
    }
};
 
