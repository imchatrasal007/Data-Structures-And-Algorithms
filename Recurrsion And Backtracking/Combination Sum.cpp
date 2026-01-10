Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> comb;
        makeCombination(candidates, target, 0, comb, 0, res);
        return res;
    }
    void makeCombination(std::vector<int>& candidates, int target, int idx, vector<int>& comb, int total, vector<vector<int>>& res) {
        if (total == target) {
            res.push_back(comb);
            return;
        }

        if (total > target || idx >= candidates.size()) {
            return;
        }

        comb.push_back(candidates[idx]);
        makeCombination(candidates, target, idx, comb, total + candidates[idx], res);
        comb.pop_back();
        makeCombination(candidates, target, idx + 1, comb, total, res);
    }    
};

